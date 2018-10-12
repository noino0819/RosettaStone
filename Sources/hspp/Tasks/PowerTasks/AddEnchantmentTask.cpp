// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <hspp/Tasks/PowerTasks/AddEnchantmentTask.h>

namespace Hearthstonepp::PowerTask
{
AddEnchantmentTask::AddEnchantmentTask(std::string&& cardID,
                                       EntityType entityType)
    : m_cardID(cardID), m_entityType(entityType)
{
    // Do nothing
}

TaskID AddEnchantmentTask::GetTaskID() const
{
    return TaskID::ADD_ENCHANTMENT;
}

MetaData AddEnchantmentTask::Impl(Player&, Player&)
{
    Card enchantmentCard = Cards::GetInstance()->FindCardByID(m_cardID);
    if (enchantmentCard.id.empty())
    {
        return MetaData::NULLPTR;
    }

    Power* power = Cards::GetInstance()->FindCardByID(m_cardID).power;
    if (power == nullptr)
    {
        return MetaData::NULLPTR;
    }

    power->enchant->ActivateTo(target);

    return MetaData::ADD_ENCHANTMENT_SUCCESS;
}
}  // namespace Hearthstonepp::PowerTask