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
ms.openlocfilehash: 241f31717274c73a658f4cddf4e6e1ef4e40b402
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50457662"
---
# <a name="getprocaddress"></a>GetProcAddress

Processos que estejam vinculando explicitamente para uma DLL chamam [GetProcAddress](/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) para obter o endereço de uma função exportada na DLL. Você pode usar o ponteiro de função retornado para chamar a função DLL. **GetProcAddress** leva como parâmetros o identificador de módulo DLL (retornado por **LoadLibrary**, `AfxLoadLibrary`, ou **GetModuleHandle**) e usa o nome da função que você deseja a chamada ou o ordinal de exportação da função.

Como você está chamando a função DLL por meio de um ponteiro e não há nenhuma verificação de tipo de tempo de compilação, certifique-se de que os parâmetros para a função estão corretos para que você não ultrapasse a memória alocada na pilha e causar uma violação de acesso. Uma maneira para ajudar a fornecer segurança de tipos é examinar os protótipos de função das funções exportadas e criar typedefs correspondentes para ponteiros de função. Por exemplo:

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

Como você especifica a função que você deseja ao chamar **GetProcAddress** depende de como a DLL foi criada.

Você pode obter o ordinal de exportação somente se a DLL que você está vinculando é criada com um arquivo de definição (. def) do módulo e se os ordinais estiverem listados com funções na **exportações** seção do arquivo. def da DLL. Chamando **GetProcAddress** com uma exportação ordinal, em vez do nome da função, é ligeiramente mais rápido se a DLL tem muitas funções exportadas porque os ordinais de exportação servem como índices a DLL de tabela de exportação. Com um ordinal de exportação **GetProcAddress** pode localizar a função diretamente, em vez de comparar o nome especificado para os nomes de função na tabela de exportação da DLL. No entanto, você deve chamar **GetProcAddress** com um ordinal de exportação somente se você tiver controle sobre a atribuição dos ordinais para as funções exportadas no arquivo. def.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Como vincular implicitamente para uma DLL](../build/linking-an-executable-to-a-dll.md#linking-implicitly)

- [Determinar qual método de vinculação usar](../build/linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [LoadLibrary e AfxLoadLibrary](../build/loadlibrary-and-afxloadlibrary.md)

- [FreeLibrary](/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary)

- [Exportando de uma DLL usando arquivos DEF](../build/exporting-from-a-dll-using-def-files.md)

## <a name="see-also"></a>Consulte também

[DLLs no Visual C++](../build/dlls-in-visual-cpp.md)