---
title: "Erro das Ferramentas de Vinculador LNK1309 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK1309"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1309"
ms.assetid: 10146071-883f-4849-97d1-c7468f90efbb
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1309
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

tipo 1 módulo detectado; inválido com a opção \/CLRIMAGETYPE:type2  
  
 Um tipo de imagem de CLR foi solicitado com **\/CLRIMAGETYPE** mas o vinculador não pôde produzir uma imagem desse tipo porque um ou vários módulos eram incompatíveis com aquele tipo.  
  
 Por exemplo, você verá LNK1309 se você especificar **\/CLRIMAGETYPE:safe** e você passa um módulo compilado com **\/clr:pure**.  
  
 Você também verá LNK1309 se você tentar criar um aplicativo puro parcialmente confiável de CLR usando o ptrustu de \[\] .lib.  Para obter informações sobre como criar um aplicativo parcialmente confiável, consulte [Como criar um aplicativo confiável parcialmente removendo a dependência da DLL de biblioteca CRT](../../dotnet/create-a-partially-trusted-application.md).  
  
 Para obter mais informações, consulte [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md) e [\/CLRIMAGETYPE \(especificar tipo de imagem CLR\)](../Topic/-CLRIMAGETYPE%20\(Specify%20Type%20of%20CLR%20Image\).md).