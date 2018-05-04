---
title: Descarregando de maneira explícita uma DLL carregada com atraso | Microsoft Docs
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
ms.openlocfilehash: 171acf9689c01649b86c2383d17136c926e25c57
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="explicitly-unloading-a-delay-loaded-dll"></a>Descarregando de maneira explícita uma DLL carregada com atraso
O [/Delay](../../build/reference/delay-delay-load-import-settings.md): opção de vinculador unload permite descarregar uma DLL carregada com atraso. Por padrão, quando seu código descarrega a DLL (usando /Delay: Unload e **__FUnloadDelayLoadedDLL2**), as importações carregadas com atraso permanecerão na tabela de endereço de importação (IAT). No entanto, se você usar /Delay: Unload na linha de comando do vinculador, a função auxiliar dará suporte a descarregamento explícito da DLL, redefinindo o IAT para sua forma original; os ponteiros inválido agora serão substituídos. IAT é um campo de [ImgDelayDescr](../../build/reference/calling-conventions-parameters-and-return-type.md) que contém o endereço de uma cópia do original IAT (se houver).  
  
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
 Observações importantes sobre descarregando uma DLL carregada com atraso:  
  
-   Você pode encontrar a implementação de **__FUnloadDelayLoadedDLL2** função no arquivo \VC7\INCLUDE\DELAYHLP. CPP.  
  
-   O parâmetro name do **__FUnloadDelayLoadedDLL2** função deve corresponder exatamente (incluindo caso) o que a biblioteca de importação contém (ou cadeia de caracteres também é a tabela de importação da imagem). Você pode exibir o conteúdo da biblioteca de importação com [/DEPENDENTS DUMPBIN](../../build/reference/dependents.md). Se desejar fazer uma correspondência de cadeia de caracteres de maiusculas e minúsculas, você pode atualizar **__FUnloadDelayLoadedDLL2** para usar as funções de cadeia de caracteres de CRT ou uma chamada de API do Windows.  
  
 Consulte [descarregando uma DLL Delay-Loaded](../../build/reference/unloading-a-delay-loaded-dll.md) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)