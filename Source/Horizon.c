#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiApplicationEntryPoint.h>

EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  volatile UINTN i;
  EFI_INPUT_KEY Key;

  //
  // Splash Screen
  //
  SystemTable->ConOut->ClearScreen(SystemTable->ConOut);

  SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 30, 8);
  Print(L"Horizon OS");

  SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 20, 10);
  Print(L"Built for people, not money.");

  SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 31, 12);
  Print(L"Loading...");

  //
  // Delay
  //
  for (i = 0; i < 3000000000ULL; i++)
  {
  }

  //
  // Lock Screen
  //
  SystemTable->ConOut->ClearScreen(SystemTable->ConOut);

  SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 30, 8);
  Print(L"Horizon OS");

  SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 32, 10);
  Print(L"Ghost");

  SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 27, 12);
  Print(L"System Locked");

  SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 24, 14);
  Print(L"Press U To Unlock");

  //
  // Wait for U
  //
  while (1)
  {
    if (SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &Key) == EFI_SUCCESS)
    {
      if (Key.UnicodeChar == L'u' || Key.UnicodeChar == L'U')
      {
        break;
      }
    }
  }

  //
  // Unlock Screen
  //
  SystemTable->ConOut->ClearScreen(SystemTable->ConOut);

  SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 30, 8);
  Print(L"Horizon OS");

  SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 28, 10);
  Print(L"Welcome Ghost");

  SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 25, 12);
  Print(L"System Unlocked");

  SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 22, 14);
  Print(L"Press Any Key To Exit");

  while (SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &Key) != EFI_SUCCESS)
  {
  }

  return EFI_SUCCESS;
}