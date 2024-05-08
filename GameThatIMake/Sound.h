#pragma once
#include "SDL_mixer.h"
#include <map>
#include <string>

class Sound
{
public:
	static std::string pathMusic ;
	static bool onMusic;
	static bool onChunk;

	void PlayJumpSound()
	{
		if(onChunk)
		{
			InitJumpSound();
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayMenuSound()
	{
		if(onMusic)
		{
			InitMenuSound();
			Mix_PlayMusic(music, -1);
		}
	}

	void PlayMenuMusic()
	{
		if (onMusic)
		{
			Mix_PlayMusic(music, -1);
		}
	}


	void PlayCCSound()
	{
		if(onChunk)
		{
			InitCCSound();
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayGunSound()
	{
		if(onChunk)
		{
			InitGunSound();
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayCoinSound()
	{
		if(onChunk)
		{
			InitCoinSound();
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayOcSound()
	{
		if(onChunk)
		{
			InitOcSound();
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayGOSSound()
	{

		InitGOSSound();
		Mix_PlayMusic(music, -1);
	}

	void PlayLenThienDangSound()
	{
		if(onMusic)
		{
			InitLenThienDangSound();
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void Clean()
	{
		Mix_FreeChunk(chunk);
	}

	void Clear()
	{
		Mix_FreeMusic(music);
		Mix_CloseAudio();
	}

	void resume()
	{
		if(onMusic)
		Mix_ResumeMusic();
	}

	void pause()
	{
		Mix_PauseMusic();
	}
	void changeMusic(std::string path)
	{
		pathMusic = path;
	}
private:
	Mix_Music* music;
	Mix_Chunk* chunk;
	std::map<std::string, Mix_Music*> nhacNen;

	void InitJumpSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		chunk = Mix_LoadWAV("sound/JumpVideoGame.wav");
	}

	void InitMenuSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		music = Mix_LoadMUS(pathMusic.c_str());
	}

	void InitGOSSound()
	{

		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		music = Mix_LoadMUS("sound/thienDang.mp3");
	}

	void InitCCSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		chunk = Mix_LoadWAV("sound/adventure.mp3");
	}

	void InitGunSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		chunk = Mix_LoadWAV("sound/gun.mp3");
	}

	void InitCoinSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		chunk = Mix_LoadWAV("sound/coin.wav");
	}

	void InitOcSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		chunk = Mix_LoadWAV("sound/oc.mp3");
	}

	void InitLenThienDangSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		chunk = Mix_LoadWAV("sound/lenThienDang.mp3");
	}
	void InitMetMoiSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		music = Mix_LoadMUS("sound/metMoi.mp3");
	}

};