---
title: "Classe de CAutoPtr | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CAutoPtr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAutoPtr"
ms.assetid: 08988d53-4fb0-4711-bdfc-8ac29c63f410
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAutoPtr
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa um objeto inteligente do ponteiro.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template<   
typename T  
>  
class CAutoPtr  
```  
  
#### Parâmetros  
 `T`  
 O tipo ponteiro.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAutoPtr::CAutoPtr](../Topic/CAutoPtr::CAutoPtr.md)|o construtor.|  
|[CAutoPtr::~CAutoPtr](../Topic/CAutoPtr::~CAutoPtr.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAutoPtr::Attach](../Topic/CAutoPtr::Attach.md)|Chamar esse método para executar a propriedade de um ponteiro existente.|  
|[CAutoPtr::Detach](../Topic/CAutoPtr::Detach.md)|Chamar este método para liberar a propriedade de um ponteiro.|  
|[CAutoPtr::Free](../Topic/CAutoPtr::Free.md)|Chamar esse método para excluir um objeto apontado pela `CAutoPtr`.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAutoPtr::operator T\*](../Topic/CAutoPtr::operator%20T*.md)|o operador cast.|  
|[CAutoPtr::operator \=](../Topic/CAutoPtr::operator%20=.md)|o operador de atribuição.|  
|[CAutoPtr::operator \- \>](../Topic/CAutoPtr::operator%20-%3E.md)|O operador de ponteiro\-à\- membro.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAutoPtr::m\_p](../Topic/CAutoPtr::m_p.md)|A variável de membro de dados do ponteiro.|  
  
## Comentários  
 Essa classe fornece métodos para criar e gerenciar um ponteiro inteligente, que ajuda a proteger contra vazamentos de memória automaticamente liberando recursos quando ele está fora do escopo.  
  
 Além de isso, o construtor de impressão `CAutoPtr` e o operador de atribuição transferem a propriedade de ponteiro, copiando o ponteiro da fonte para o ponteiro de destino e definindo o ponteiro de origem PARA ANULAR.  Portanto é impossível ter dois objetos cada um de `CAutoPtr` que armazena o mesmo ponteiro, e isso reduz a possibilidade de excluir o mesmo ponteiro duas vezes.  
  
 `CAutoPtr` também simplifica a criação das coleções de ponteiros.  Em vez de derivar uma classe de coleção e substituir o destrutor, é mais simples fazer uma coleção de objetos de `CAutoPtr` .  Quando a coleção é excluída, os objetos de `CAutoPtr` sairão de escopo e excluir\-se\-9&z automaticamente.  
  
 [CHeapPtr](../../atl/reference/cheapptr-class.md) e variantes funcionam da mesma forma como `CAutoPtr`, exceto que aloca e libera memória usando funções diferentes de heap C\+\+ em vez de **new** e os operadores de **delete** .  [CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md) é semelhante a `CAutoPtr`, a única diferença é que usa **vector new\[\]** e **vector delete\[\]** para atribuir e liberar memória.  
  
 Consulte também [CAutoPtrArray](../../atl/reference/cautoptrarray-class.md) e [CAutoPtrList](../../atl/reference/cautoptrlist-class.md) quando as matrizes ou listas de ponteiros inteligentes são necessárias.  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Exemplo  
 [!CODE [NVC_ATL_Utilities#74](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#74)]  
  
## Consulte também  
 [Classe de CHeapPtr](../../atl/reference/cheapptr-class.md)   
 [Classe de CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)