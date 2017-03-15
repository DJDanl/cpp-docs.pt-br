---
title: "Convertendo projetos do modo misto em linguagem intermedi&#225;ria pura | Microsoft Docs"
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
  - "idioma intermediário, aplicativos de modo misto"
  - "aplicativos de modo misto"
  - "aplicativos de modo misto, idioma intermediário"
  - "projetos [C++], convertendo em idioma intermediário"
ms.assetid: 855f9e3c-4f09-4bfe-8eab-a45f68292be9
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convertendo projetos do modo misto em linguagem intermedi&#225;ria pura
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Todos os projetos do Visual C\+\+ CLR vinculam a bibliotecas de tempo de execução C por padrão.  Consequentemente, esses projetos são classificados como aplicativos de modo misto, porque combinam o código nativo com o código que se destinam Common Language Runtime \(código gerenciado\).  Quando são criados, serão criados em linguagem intermediária \(IL\), também conhecido como a linguagem intermediária da Microsoft \(MSIL\).  
  
### Para converter seu aplicativo de modo misto em linguagem intermediária puro  
  
1.  Remova os links a [Bibliotecas de tempo de execução C](../c-runtime-library/crt-library-features.md) \(CRT\):  
  
    1.  No arquivo .cpp que define o ponto de entrada de seu aplicativo, altere o ponto de entrada para `Main()`.  Usar `Main()` indica que o projeto não está vinculada ao CRT.  
  
    2.  No Solution Explorer, clique com o botão direito do mouse no projeto e selecione **Propriedades** no menu de atalho para abrir as páginas de propriedades para seu aplicativo.  
  
    3.  Na página de propriedades do projeto de **Avançado** para **Vinculador**, selecione **Ponto de entrada** e digite em **Principal** nesse campo.  
  
    4.  Para aplicativos do console, na página de propriedades do projeto de **Sistema** para **Vinculador**, selecione o campo de **SubSystem** e altere\-a para **Console \(\/SUBSYSTEM:CONSOLE\)**.  
  
        > [!NOTE]
        >  Não defina essa propriedade para aplicativos Windows Forms como o campo de **SubSystem** é definido como **Windows \(\/SUBSYSTEM:WINDOWS\)** por padrão.  
  
    5.  Em stdafx.h, comentam out todas as instruções de `#include` .  Por exemplo, nos aplicativos do console:  
  
        ```  
        // #include <iostream>  
        // #include <tchar.h>  
        ```  
  
         \- ou \-  
  
         Por exemplo, em aplicativos do Windows Forms:  
  
        ```  
        // #include <stdlib.h>  
        // #include <malloc.h>  
        // #include <memory.h>  
        // #include <tchar.h>  
        ```  
  
    6.  Para aplicativos Windows Forms, em Form1.cpp, a utilização de comentários para fora da instrução `#include` que referencia windows.h.  Por exemplo:  
  
        ```  
        // #include <windows.h>  
        ```  
  
2.  Adicione o seguinte código para stdafx.h:  
  
    ```  
    #ifndef __FLTUSED__  
    #define __FLTUSED__  
       extern "C" __declspec(selectany) int _fltused=1;  
    #endif  
    ```  
  
3.  Remover todos os tipos não gerenciada:  
  
    1.  Onde apropriada, substitua tipos não gerenciados por referências às estruturas de namespace de [O sistema](https://msdn.microsoft.com/en-us/library/system.appdomainmanager.appdomainmanager.aspx) .  Os tipos gerenciados comuns são listados na seguinte tabela:  
  
        |Estrutura|Descrição|  
        |---------------|---------------|  
        |[\<caps:sentence id\="tgt24" sentenceid\="84e2c64f38f78ba3ea5c905ab5a2da27" class\="tgtSentence"\>Booleano\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.boolean\(v=vs.140\).aspx)|Representa um valor booliano.|  
        |[\<caps:sentence id\="tgt26" sentenceid\="40ea57d3ee3c07bf1c102b466e1c3091" class\="tgtSentence"\>Byte\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.byte\(v=vs.140\).aspx)|Representa um inteiro não assinado de 8 bits.|  
        |[\<caps:sentence id\="tgt28" sentenceid\="a87deb01c5f539e6bda34829c8ef2368" class\="tgtSentence"\>Char\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.char\(v=vs.140\).aspx)|Representa um caractere Unicode.|  
        |[\<caps:sentence id\="tgt30" sentenceid\="dfeaaeb4316477bd556ea5e8c3295887" class\="tgtSentence"\>DateTime\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.datetime.datetime.aspx)|Representa um instante no tempo, normalmente expresso como uma data e uma hora.|  
        |[\<caps:sentence id\="tgt32" sentenceid\="bdaa3c20a3e3851599514f7c6be5f62f" class\="tgtSentence"\>Decimal\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.decimal\(v=vs.140\).aspx)|Representa um número decimal.|  
        |[\<caps:sentence id\="tgt34" sentenceid\="e8cd7da078a86726031ad64f35f5a6c0" class\="tgtSentence"\>Double\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.double\(v=vs.140\).aspx)|Representa um número de ponto flutuante de precisão dupla.|  
        |[\<caps:sentence id\="tgt36" sentenceid\="1e0ca5b1252f1f6b1e0ac91be7e7219e" class\="tgtSentence"\>Guid\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.guid\(v=vs.140\).aspx)|Representa um GUID \(identificador global exclusivo\).|  
        |[\<caps:sentence id\="tgt38" sentenceid\="ce80d5ec65b1d2a2f1049eadc100db23" class\="tgtSentence"\>Int16\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.int16\(v=vs.140\).aspx)|Representa um inteiro com sinal de 16 bits.|  
        |[\<caps:sentence id\="tgt40" sentenceid\="0241adbbd83925f051b694d40f02747f" class\="tgtSentence"\>Int32\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.int32\(v=vs.140\).aspx)|Representa um inteiro com sinal de 32 bits.|  
        |[\<caps:sentence id\="tgt42" sentenceid\="ff9b3f96d37353c528517bc3656a00a8" class\="tgtSentence"\>Int64\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.int64\(v=vs.140\).aspx)|Representa um inteiro com sinal de 64 bits.|  
        |[\<caps:sentence id\="tgt44" sentenceid\="7f1db863563907cf33604ed7fad6b111" class\="tgtSentence"\>IntPtr\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.intptr\(v=vs.140\).aspx)|Um tipo de plataforma específica que é usada para representar um ponteiro ou um identificador.|  
        |[\<caps:sentence id\="tgt46" sentenceid\="943756eb7841efcc43b7cd37d7254c76" class\="tgtSentence"\>SByte\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.byte.aspx)|Representa um inteiro com sinal de 8 bits.|  
        |[\<caps:sentence id\="tgt48" sentenceid\="dd5c07036f2975ff4bce568b6511d3bc" class\="tgtSentence"\>Single\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.single.aspx)|Representa um número de ponto flutuante de precisão única.|  
        |[\<caps:sentence id\="tgt50" sentenceid\="90150402997ea9c8dc45cc4d41bb28cb" class\="tgtSentence"\>TimeSpan\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.timespan\(v=vs.140\).aspx)|Representa um intervalo de tempo.|  
        |[\<caps:sentence id\="tgt52" sentenceid\="a00ef2ef85ff67b7b39339886f19044f" class\="tgtSentence"\>UInt16\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.uint16\(v=vs.140\).aspx)|Representa um inteiro não assinado de 16 bits.|  
        |[\<caps:sentence id\="tgt54" sentenceid\="3de84ad0700f2a1571f633d399e1900e" class\="tgtSentence"\>UInt32\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.uint32\(v=vs.140\).aspx)|Representa um inteiro não assinado de 32 bits.|  
        |[\<caps:sentence id\="tgt56" sentenceid\="2e8d31865e5d4b9d8611e1b991baed07" class\="tgtSentence"\>UInt64\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.uint64\(v=vs.140\).aspx)|Representa um inteiro não assinado de 64 bits.|  
        |[\<caps:sentence id\="tgt58" sentenceid\="92d74abda31865424016b16e2c806a66" class\="tgtSentence"\>UIntPtr\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.uintptr\(v=vs.140\).aspx)|Um tipo de plataforma específica que é usada para representar um ponteiro ou um identificador.|  
        |[\<caps:sentence id\="tgt60" sentenceid\="cab8111fd0b710a336c898e539090e34" class\="tgtSentence"\>Nulo\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.void\(v=vs.140\).aspx)|Indica um método que não retorna um valor; isto é, o método tem o tipo de retorno nulo.|