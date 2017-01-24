---
title: "Ponteiros baseados (C) | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "Palavra-chave __based [C]"
  - "abordando com base em"
  - "ponteiros baseados"
  - "ponteiros, baseado"
ms.assetid: b5446920-89e0-4e2f-91f3-1f2a769a08e8
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Ponteiros baseados (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 [\_\_based \(Referência do C\+\+\)](../Topic/Based%20Pointers%20\(C++\).md)  
  
 Para os compiladores C de 32 bits e de 64 bits da Microsoft, um ponteiro baseado é um deslocamento de 32 bits ou de 64 bits a partir de um base de ponteiro de 32 bits ou de 64 bits.  O endereçamento baseado é útil para controlar as seções nas quais os objetos são alocados, diminuindo assim o tamanho do arquivo executável e aumentando a velocidade de execução.  Em geral, o formato para especificar um ponteiro baseado é  
  
```  
  
type __based( base ) declarator   
```  
  
 A variante "ponteiro de base" do endereçamento baseado permite especifica um ponteiro como base.  O ponteiro baseado, portanto, é um deslocamento para a seção de memória que começa no início do ponteiro no qual ele é baseado.  Os ponteiros com base em endereços de ponteiro são o único formato da palavra\-chave `__based` válido em compilações de 32 bits e de 64 bits.  Nessas compilações, ele são deslocamentos de 32 bits ou de 64 bits a partir de uma base de 32 bits ou de 64 bits.  
  
 Um uso para ponteiros baseados em ponteiros é para identificadores persistentes que contêm ponteiros.  Uma lista vinculada que consiste em ponteiros baseados em um ponteiro pode ser salva em disco e depois ser recarregada em outro local na memória, com os ponteiros permanecendo válidos.  
  
 O exemplo a seguir mostra um ponteiro com base em um ponteiro.  
  
```  
void *vpBuffer;  
  
struct llist_t  
{  
    void __based( vpBuffer ) *vpData;  
    struct llist_t __based( vpBuffer ) *llNext;  
};  
```  
  
 O ponteiro `vpBuffer` é atribuído ao endereço da memória alocada em algum momento posterior no programa.  A lista vinculada é realocada em relação ao valor de `vpBuffer`.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Declaradores e declarações variáveis](../c-language/declarators-and-variable-declarations.md)