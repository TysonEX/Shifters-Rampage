#pragma once
#include "Globals.h"
#include "AnimatedGameSprite.h"

enum PlayerState
{
	IDLE,
	RUNNING,
	JUMPING_UP,
	FALLING,
	ATTACKING
};

enum class SwordForm
{
	RED,
	GREEN,
	BLUE
};

class Player : public AnimatedGameSprite
{
public:
	Player();
	Player(Graphics& graphics, sf::Vector2i spawnPoint);
	~Player();

	bool IsGrounded() const;
	Direction GetFacing() const;
	PlayerState GetPlayerState() const;
	const float GetDamageAmount() const;
	void SetGrounded(bool grounded);
	const float GetKnockbackAmount() const;
	SwordForm GetSwordForm() const;
	bool IsPlayerDead() const;

	void ResetHP();

	void Update(float elapsedTime);
	void Draw(Graphics& graphics);

	void MoveLeft();
	void MoveRight();
	void StopMoving();

	void Jump();

	void Attack();

	void TransformRed();
	void TransformGreen();
	void TransformBlue();

	const int GetHealth() const;
	void DepleteHealth(float amount);
	void HealHealth();

	bool CheckAttackHit(const sf::IntRect& enemyBox);

	void SetupAnimations();
	void SetupHitboxes();
	void AnimationDone(const std::string& currentAnimation);

	void HandleTileCollision(std::vector<sf::IntRect>& others);

private:
	float dx, dy;
	Direction facing;
	bool grounded;
	PlayerState state;
	float hp;
	sf::IntRect currentHitbox;
	SwordForm form;
	bool isDead;

	std::map<std::string, std::vector<sf::IntRect> > hitBoxes;
};
