---
title: "Descarregando de maneira expl&#237;cita uma DLL carregada com atraso | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /DELAY:UNLOAD"
  - "__FUnloadDelayLoadedDLL2"
  - "Opção de vinculador DELAY:UNLOAD"
  - "carregamento atrasado de DLLs, descarregando"
ms.assetid: 1c4c5172-fd06-45d3-9e4f-f12343176b3c
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Descarregando de maneira expl&#237;cita uma DLL carregada com atraso
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

[\/delay](../../build/reference/delay-delay-load-import-settings.md): descarregar a opção do vinculador permite que você descarregar uma DLL que foi carregado atraso.  Por padrão, quando seu código descarrega o DLL \(usando \/delay:unload e **\_\_FUnloadDelayLoadedDLL2**\), as importações atraso\- carregadas permanecem na tabela de endereço \(IAT\) de importação.  No entanto, se você usar \/delay:unload na linha de comando do vinculador, a função auxiliar dará suporte a descarga explícito da DLL, redefinindo o IAT ao seu formato original; os ponteiros agora inválidos serão substituídos.  O IAT é um campo em [ImgDelayDescr](../../build/reference/calling-conventions-parameters-and-return-type.md) que contém o endereço de uma cópia original IAT \(se houver\).  
  
## Exemplo  
  
### Código  
  
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
  
### Comentários  
 Observações importantes em descarregar uma DLL atraso\- carregado:  
  
-   Você pode localizar a implementação da função **\_\_FUnloadDelayLoadedDLL2** no arquivo \\VC7\\INCLUDE\\DELAYHLP.CPP.  
  
-   O parâmetro de nome da função de **\_\_FUnloadDelayLoadedDLL2** deve corresponder exatamente \(inclusive\) casos que a biblioteca de importação \(contém a cadeia de caracteres também está na tabela de importação na imagem\).  Você pode exibir o conteúdo da biblioteca de importação com [DUMPBIN \/DEPENDENTS](../Topic/-DEPENDENTS.md).  Se uma correspondência sem diferenciação de maiúsculas e minúsculas de cadeia de caracteres for desejada, você pode atualizar **\_\_FUnloadDelayLoadedDLL2** para usar uma das funções de cadeia de caracteres de CRT ou de uma chamada à API do windows.  
  
 Consulte [Descarregando DLL Atraso\- carregado](../../build/reference/unloading-a-delay-loaded-dll.md) para obter mais informações.  
  
## Consulte também  
 [Suporte de vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)