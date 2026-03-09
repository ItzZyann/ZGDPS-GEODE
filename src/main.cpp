#include <Geode/Geode.hpp>

// default modifiers
// i dont wanna create new files
// for these things
#include <Geode/modify/GManager.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/GameStatsManager.hpp>

// for save file
// idk why this called GManager
// why not just cram it on GameManager?
class $modify(GManager) {
	void setup() {
		auto compare = std::string(m_fileName);
		compare.insert(std::string_view(compare).find(".dat"), "ZyannGDPS");
		m_fileName = compare;

		GManager::setup();
	}
};

// handle for unlock all
// icons and colors
class $modify(GameManager) {
    bool isIconUnlocked(int pID, IconType pType) { return true; }
    bool isColorUnlocked(int pID, UnlockType pType) { return true; }
};

// handle for unlocking
// custom music and practice
// music sync
class $modify(GameStatsManager) {
    bool isItemUnlocked(UnlockType pType, int pID) {
        if(pType == UnlockType::GJItem && pID == 16 || pID == 17) {
            return true;
        }

        return GameStatsManager::isItemUnlocked(pType, pID);
    }
};