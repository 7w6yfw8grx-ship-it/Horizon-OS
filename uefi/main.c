#include <efi.h>
#include <efilib.h>

EFI_STATUS EFIAPI efi_main(
    EFI_HANDLE ImageHandle,
    EFI_SYSTEM_TABLE *SystemTable)
{
    InitializeLib(ImageHandle, SystemTable);

    Print(L"HorizonOS\r\n");
    Print(L"Built for people, not money.\r\n");

    while (1)
    {
    }

    return EFI_SUCCESS;
}