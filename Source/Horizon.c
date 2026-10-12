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
  EFI_INPUT_KEY Key;

  Print(L"\r\n");
  Print(L"=================================\r\n");
  Print(L"         Horizon OS\r\n");
  Print(L"=================================\r\n");
  Print(L"\r\n");
  Print(L"Built for people, not money.\r\n");
  Print(L"\r\n");
  Print(L"Press any key to exit...\r\n");

  //
  // Wait for a key
  //
  while (SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &Key) != EFI_SUCCESS)
  {
  }

  return EFI_SUCCESS;
}
