---
title: Convertendo projetos do modo em linguagem intermediária pura misto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- intermediate language, mixed-mode applications
- mixed-mode applications
- mixed-mode applications, intermediate language
- projects [C++], converting to intermediate language
ms.assetid: 855f9e3c-4f09-4bfe-8eab-a45f68292be9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: ad39f7943effdea8029390971071724bf2294bdf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="converting-projects-from-mixed-mode-to-pure-intermediate-language"></a>Convertendo projetos do modo misto em linguagem intermediária pura
Todos os projetos de CLR do Visual C++ link para as bibliotecas de tempo de execução C por padrão. Consequentemente, esses projetos são classificados como aplicativos de modo misto, porque eles combinam código nativo com o código que tem como alvo o common language runtime (código gerenciado). Quando eles são compilados, eles são compilados na linguagem intermediária (IL), também conhecido como Microsoft intermediate language (MSIL).  
  
### <a name="to-convert-your-mixed-mode-application-into-pure-intermediate-language"></a>Para converter seu aplicativo de modo misto em linguagem intermediária pura  
  
1.  Remover links para o [bibliotecas em tempo de execução C](../c-runtime-library/crt-library-features.md) (CRT):  
  
    1.  No arquivo. cpp definindo o ponto de entrada do seu aplicativo, altere o ponto de entrada para `Main()`. Usando `Main()` indica que o projeto não contém links para CRT.  
  
    2.  No Gerenciador de soluções, clique com o botão direito e selecione **propriedades** no menu de atalho para abrir as páginas de propriedade para o seu aplicativo.  
  
    3.  No **avançado** página de propriedades do projeto para o **vinculador**, selecione o **ponto de entrada** e, em seguida, digite **principal** neste campo.  
  
    4.  Para aplicativos de console, no **sistema** página de propriedades do projeto para o **vinculador**, selecione o **subsistema** campo e mude-a para **Console (/ Subsystem:console)**.  
  
        > [!NOTE]
        >  Você não precisa definir essa propriedade para aplicativos de formulários do Windows porque o **subsistema** campo é definido como **Windows (/ subsistema: WINDOWS)** por padrão.  
  
    5.  Em Stdafx. h, comente todas as `#include` instruções. Por exemplo, em aplicativos de console:  
  
        ```  
        // #include <iostream>  
        // #include <tchar.h>  
        ```  
  
         -ou-  
  
         Por exemplo, em aplicativos de formulários do Windows:  
  
        ```  
        // #include <stdlib.h>  
        // #include <malloc.h>  
        // #include <memory.h>  
        // #include <tchar.h>  
        ```  
  
    6.  Para aplicativos de formulários do Windows, no Form1, comente a `#include` instrução que referencia Windows. h. Por exemplo:  
  
        ```  
        // #include <windows.h>  
        ```  
  
2.  Adicione o seguinte código ao Stdafx. h:  
  
    ```  
    #ifndef __FLTUSED__  
    #define __FLTUSED__  
       extern "C" __declspec(selectany) int _fltused=1;  
    #endif  
    ```  
  
3.  Remova todos os tipos não gerenciados:  
  
    1.  Onde for apropriado, substitua tipos não gerenciados por referências às estruturas do [sistema](https://msdn.microsoft.com/en-us/library/system.appdomainmanager.appdomainmanager.aspx) namespace. Tipos gerenciados comuns são listados na tabela a seguir:  
  
        |Estrutura|Descrição|  
        |---------------|-----------------|  
        |[Booliano](https://msdn.microsoft.com/en-us/library/system.boolean\(v=vs.140\).aspx)|Representa um valor booliano.|  
        |[Byte](https://msdn.microsoft.com/en-us/library/system.byte\(v=vs.140\).aspx)|Representa um inteiro sem sinal de 8 bits.|  
        |[Char](https://msdn.microsoft.com/en-us/library/system.char\(v=vs.140\).aspx)|Representa um caractere Unicode.|  
        |[DateTime](https://msdn.microsoft.com/en-us/library/system.datetime.datetime.aspx)|Representa um momento no tempo, geralmente expresso como uma data e hora do dia.|  
        |[Decimal](https://msdn.microsoft.com/en-us/library/system.decimal\(v=vs.140\).aspx)|Representa um número decimal.|  
        |[Duplo](https://msdn.microsoft.com/en-us/library/system.double\(v=vs.140\).aspx)|Representa um número de ponto flutuante de precisão dupla.|  
        |[Guid](https://msdn.microsoft.com/en-us/library/system.guid\(v=vs.140\).aspx)|Representa um identificador global exclusivo (GUID).|  
        |[Int16](https://msdn.microsoft.com/en-us/library/system.int16\(v=vs.140\).aspx)|Representa um inteiro com sinal de 16 bits.|  
        |[Int32](https://msdn.microsoft.com/en-us/library/system.int32\(v=vs.140\).aspx)|Representa um inteiro com sinal de 32 bits.|  
        |[Int64](https://msdn.microsoft.com/en-us/library/system.int64\(v=vs.140\).aspx)|Representa um inteiro com sinal de 64 bits.|  
        |[IntPtr](https://msdn.microsoft.com/en-us/library/system.intptr\(v=vs.140\).aspx)|Um tipo específico da plataforma que é usado para representar um ponteiro ou um identificador.|  
        |[SByte](https://msdn.microsoft.com/en-us/library/system.byte.aspx)|Representa um inteiro com sinal de 8 bits.|  
        |[Simples](https://msdn.microsoft.com/en-us/library/system.single.aspx)|Representa um número de ponto flutuante de precisão simples.|  
        |[TimeSpan](https://msdn.microsoft.com/en-us/library/system.timespan\(v=vs.140\).aspx)|Representa um intervalo de tempo.|  
        |[UInt16](https://msdn.microsoft.com/en-us/library/system.uint16\(v=vs.140\).aspx)|Representa um inteiro sem sinal de 16 bits.|  
        |[UInt32](https://msdn.microsoft.com/en-us/library/system.uint32\(v=vs.140\).aspx)|Representa um inteiro sem sinal de 32 bits.|  
        |[UInt64](https://msdn.microsoft.com/en-us/library/system.uint64\(v=vs.140\).aspx)|Representa um inteiro sem sinal de 64 bits.|  
        |[UIntPtr](https://msdn.microsoft.com/en-us/library/system.uintptr\(v=vs.140\).aspx)|Um tipo específico da plataforma que é usado para representar um ponteiro ou um identificador.|  
        |[void](https://msdn.microsoft.com/en-us/library/system.void\(v=vs.140\).aspx)|Indica um método que não retorna um valor. ou seja, o método tem o tipo de retorno void.|