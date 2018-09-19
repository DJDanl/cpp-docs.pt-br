---
title: Descarregando de maneira explícita uma DLL carregadas com atraso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- /DELAY:UNLOAD linker option
- DELAY:UNLOAD linker option
- __FUnloadDelayLoadedDLL2
- delayed loading of DLLs, unloading
ms.assetid: 1c4c5172-fd06-45d3-9e4f-f12343176b3c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0ad52e8efde017ce7be6132594552e13584b38dc
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45705322"
---
# <a name="explicitly-unloading-a-delay-loaded-dll"></a>Descarregando de maneira explícita uma DLL carregada com atraso

O [/Delay](../../build/reference/delay-delay-load-import-settings.md): opção de vinculador unload permite que você descarregar uma DLL que foi carregado de atraso. Por padrão, quando seu código descarrega a DLL (usando /Delay: Unload e **__FUnloadDelayLoadedDLL2**), as importações carregadas com atraso permanecerão na tabela de endereços de importação (IAT). No entanto, se você usar /Delay: Unload na linha de comando do vinculador, a função auxiliar dará suporte a descarregamento explícito da DLL, redefinindo o IAT para sua forma original; os ponteiros inválido agora serão substituídos. O IAT é um campo de [ImgDelayDescr](../../build/reference/calling-conventions-parameters-and-return-type.md) que contém o endereço de uma cópia da IAT original (se houver).

## <a name="example"></a>Exemplo

### <a name="code"></a>Código

```
// link with /link /DELAYLOAD:MyDLL.dll /DELAY:UNLOAD
#include <windows.h>
#include <delayimp.h>
#include "MyDll.h"
#include <stdio.h>

#pragma comment(lib, "delayimp")
#pragma comment(lib, "MyDll")
int main()
{
    BOOL TestReturn;
    // MyDLL.DLL will load at this point
    fnMyDll();

    //MyDLL.dll will unload at this point
    TestReturn = __FUnloadDelayLoadedDLL2("MyDll.dll");

    if (TestReturn)
        printf_s("\nDLL was unloaded");
    else
        printf_s("\nDLL was not unloaded");
}
```

### <a name="comments"></a>Comentários

Observações importantes sobre descarregar a DLL carregadas com atraso:

- Você pode encontrar a implementação de **__FUnloadDelayLoadedDLL2** função no arquivo \VC7\INCLUDE\DELAYHLP. CPP.

- O parâmetro name do **__FUnloadDelayLoadedDLL2** função deve corresponder exatamente (incluindo caso) o que a biblioteca de importação contém (ou seja, cadeia de caracteres também na tabela de importação na imagem). Você pode exibir o conteúdo da biblioteca de importação com [DUMPBIN /Dependents](../../build/reference/dependents.md). Se uma correspondência não diferencia maiusculas de cadeia de caracteres for desejada, você pode atualizar **__FUnloadDelayLoadedDLL2** usar uma das funções de cadeia de caracteres de CRT ou uma chamada à API do Windows.

Ver [descarregando uma DLL Delay-Loaded](../../build/reference/unloading-a-delay-loaded-dll.md) para obter mais informações.

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)