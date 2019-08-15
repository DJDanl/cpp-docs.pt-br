---
title: GetProcAddress
ms.date: 11/04/2016
f1_keywords:
- GetProcAddress
helpviewer_keywords:
- DLLs [C++], GetProcAddress
- ordinal exports [C++]
- GetProcAddress method
ms.assetid: 48d14ae0-47ea-4c5d-96b1-2c158f1a26af
ms.openlocfilehash: 2d322cfe7d3bd60d8d702a226e181eb7b4ede963
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493247"
---
# <a name="getprocaddress"></a>GetProcAddress

Processa explicitamente o vínculo com uma DLL chamada [GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) para obter o endereço de uma função exportada na dll. Você usa o ponteiro de função retornado para chamar a função de DLL. O **GetProcAddress** usa como parâmetros o identificador do módulo de dll (retornado por `AfxLoadLibrary` **LoadLibrary**, ou **GetModuleHandle**) e usa o nome da função que você deseja chamar ou o ordinal de exportação da função.

Como você está chamando a função de DLL por meio de um ponteiro e não há nenhuma verificação de tipo em tempo de compilação, certifique-se de que os parâmetros para a função estejam corretos para que você não overstep a memória alocada na pilha e cause uma violação de acesso. Uma maneira de ajudar a fornecer segurança de tipo é examinar os protótipos de função das funções exportadas e criar TYPEDEFs correspondentes para os ponteiros de função. Por exemplo:

```
typedef UINT (CALLBACK* LPFNDLLFUNC1)(DWORD,UINT);
...

HINSTANCE hDLL;               // Handle to DLL
LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer
DWORD dwParam1;
UINT  uParam2, uReturnVal;

hDLL = LoadLibrary("MyDLL");
if (hDLL != NULL)
{
   lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL,
                                           "DLLFunc1");
   if (!lpfnDllFunc1)
   {
      // handle the error
      FreeLibrary(hDLL);
      return SOME_ERROR_CODE;
   }
   else
   {
      // call the function
      uReturnVal = lpfnDllFunc1(dwParam1, uParam2);
   }
}
```

A forma como você especifica a função desejada ao chamar **GetProcAddress** depende de como a dll foi criada.

Você só poderá obter o ordinal de exportação se a DLL à qual você está vinculando for criada com um arquivo de definição de módulo (. def) e se os ordinais estiverem listados com as funções na seção EXPORTS do arquivo. def da dll. Chamar **GetProcAddress** com um ordinal de exportação, ao contrário do nome da função, é ligeiramente mais rápido se a dll tem muitas funções exportadas porque os ordinais de exportação servem como índices para a tabela de exportação da dll. Com um ordinal de exportação, o **GetProcAddress** pode localizar a função diretamente em vez de comparar o nome especificado com os nomes de função na tabela de exportação da dll. No entanto, você deve chamar **GetProcAddress** com um ordinal de exportação somente se tiver controle sobre como atribuir os ordinais às funções exportadas no arquivo. def.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md#linking-implicitly)

- [Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [LoadLibrary e AfxLoadLibrary](loadlibrary-and-afxloadlibrary.md)

- [FreeLibrary](/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary)

- [Exportando de uma DLL usando arquivos DEF](exporting-from-a-dll-using-def-files.md)

## <a name="see-also"></a>Consulte também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
