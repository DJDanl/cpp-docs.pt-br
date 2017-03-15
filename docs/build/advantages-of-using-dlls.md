---
title: "Vantagens de usar DLLs | Microsoft Docs"
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
  - "DLLs [C++], vantagens"
  - "vinculação dinâmica [C++]"
  - "vinculação de carga dinâmica [C++]"
  - "vinculando [C++], dinâmica vs. estática"
  - "links [C++], dinâmica vs. estática"
ms.assetid: 8956c8ee-e7b3-446f-a0c6-462381747690
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Vantagens de usar DLLs
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Vincular dinâmico tem as seguintes vantagens:  
  
-   Salva a memória e reduz alternar.  Muitos processos podem usar um único DLL simultaneamente, compartilhando uma única cópia da DLL na memória.  Em contraste, o windows devem carregar uma cópia do código de biblioteca na memória para cada aplicativo que é criado com uma biblioteca de vínculo estático.  
  
-   Salva o espaço em disco.  Muitos aplicativos podem compartilhar uma única cópia da DLL no disco.  Em contraste, cada aplicativo compilado com uma biblioteca de vínculo estáticos têm o código de biblioteca vinculado na imagem executável como uma cópia separada.  
  
-   As atualizações para a DLL são mais fáceis.  Quando as funções em uma DLL mudam, os aplicativos que os utilizam não precisam ser recompilados ou relinked como argumentos e os valores de retorno da função não são alterados.  Em contraste, o código do objeto vinculado estaticamente requer que o aplicativo relinked quando a alteração de funções.  
  
-   Fornece suporte de compras de acessórios.  Por exemplo, uma DLL do driver de vídeo pode ser alterado para oferecer suporte a uma exibição que não está disponível quando o aplicativo foi enviado.  
  
-   Oferece suporte multilíngue programas.  Os programas gravados em linguagens de programação diferentes podem chamar a mesma função da DLL à medida que os programas seguem a convenção de chamada de função.  Os programas e a função da DLL devem ser compatíveis das seguintes maneiras: a ordem em que a função espera que os argumentos ser variável na pilha, se a função ou o aplicativo é responsável pela limpeza da pilha, e se qualquer argumento for transmitido em registros.  
  
-   Fornece um mecanismo para estender as classes de biblioteca MFC.  Você pode derivar classes das classes existentes MFC e colocá\-las em uma DLL de extensão MFC para os aplicativos usam MFC.  
  
-   Facilita a criação de versões internacionais.  Colocar recursos em uma DLL, é muito mais fácil criar versões internacionais de um aplicativo.  Você pode colocar as cadeias de caracteres para cada versão do idioma do aplicativo em uma DLL de recurso separado e fazer com que as versões de idioma diferentes carregar os recursos adequados.  
  
 Uma desvantagem potencial para usar DLL é que o aplicativo não é independente; depende da existência de um módulo separado da DLL.  
  
## O que você deseja fazer?  
  
-   [Exportar de uma DLL](../build/exporting-from-a-dll.md)  
  
-   [Vincular um executável para uma DLL](../build/linking-an-executable-to-a-dll.md)  
  
-   [Inicialize um DLL](../build/initializing-a-dll.md)  
  
## Que você deseja saber mais?  
  
-   [DLLs não MFC: Visão Geral](../Topic/Non-MFC%20DLLs:%20Overview.md)  
  
-   [DLL normais vinculadas estaticamente ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)  
  
-   [DLL normais vinculadas dinamicamente ao MFC](../Topic/Regular%20DLLs%20Dynamically%20Linked%20to%20MFC.md)  
  
-   [DLLs de extensão: visão geral](../build/extension-dlls-overview.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)