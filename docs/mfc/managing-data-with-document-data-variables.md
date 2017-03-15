---
title: "Gerenciando dados com vari&#225;veis de dados do documento | Microsoft Docs"
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
  - "classes [C++], friend"
  - "classes de coleções [C++], usadas pelo objeto de documento"
  - "dados [MFC]"
  - "dados [MFC], documentos"
  - "dados de documento [C++]"
  - "documentos [C++], armazenamento de dados"
  - "classes friend"
  - "variáveis de membro [C++], classe de documento"
ms.assetid: e70b87f4-8c30-49e5-8986-521c2ff91704
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciando dados com vari&#225;veis de dados do documento
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Implementar os dados do documento como as variáveis de membro do documento classe.  Por exemplo, o programa de garrancho declara um membro de dados do tipo `CObList` — uma lista vinculada que armazena ponteiros para os objetos de `CObject` .  Esta lista é usada para armazenar matrizes de pontos que formam a um lápis desenho a mão livre.  
  
 Como você implementa os dados de membro do documento dependem da natureza de seu aplicativo.  Para ajudá\-lo em expansão, fontes que MFC um grupo “coleção classificará” — matrizes, listas, mapas \(\) e dicionários, incluindo as coleções baseadas em modelos C\+\+ — junto com as classes que encapsulam uma variedade de tipos de dados comuns como `CString`, `CRect`, `CPoint`, `CSize`, e `CTime`.  Para obter mais informações sobre essas classes, consulte [Visão geral da biblioteca de classes](../mfc/class-library-overview.md)*na referência de MFC*.  
  
 Quando você define dados de membro do documento, você adicionará geralmente funções de membro à classe do documento para definir e obter itens de dados e executar outras operações úteis nelas.  
  
 As exibições acessam o objeto de documento com o ponteiro da exibição do documento, instalado na exibição no momento da criação.  Você pode recuperar esse ponteiro em funções de membro de uma exibição chamando a função de membro **GetDocument**de `CView` .  Certifique\-se de converter esse ponteiro para seu próprio tipo de documento.  Depois você pode acessar membros de documento público pelo ponteiro.  
  
 Se a transferência de dados frequente requer o acesso direto, ou você deseja usar os membros público do documento classificará, talvez você queira fazer a sua classe exibição de um amigo \(em termos de C\+\+\) da classe do documento.  
  
## Consulte também  
 [Usando documentos](../mfc/using-documents.md)