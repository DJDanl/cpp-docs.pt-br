---
title: "Classe de CMapStringToOb | Microsoft Docs"
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
  - "CMapStringToOb"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMapStringToOb"
  - "classes de coleção, mapeamento de cadeias de caracteres"
  - "cadeias de caracteres [C++], classe para mapear"
ms.assetid: 09653980-b885-4f3a-8594-0aeb7f94c601
caps.latest.revision: 20
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMapStringToOb
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma classe de coleção de dicionário que mapeia `CString` exclusivo objetos para ponteiros de `CObject` .  
  
## Sintaxe  
  
```  
class CMapStringToOb : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMapStringToOb::CMapStringToOb](../Topic/CMapStringToOb::CMapStringToOb.md)|Construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMapStringToOb::GetCount](../Topic/CMapStringToOb::GetCount.md)|Retorna o número de elementos em esse mapeamento.|  
|[CMapStringToOb::GetHashTableSize](../Topic/CMapStringToOb::GetHashTableSize.md)|Determina o número de elementos atual na tabela hash.|  
|[CMapStringToOb::GetNextAssoc](../Topic/CMapStringToOb::GetNextAssoc.md)|Obtém o próximo elemento para iterar.|  
|[CMapStringToOb::GetSize](../Topic/CMapStringToOb::GetSize.md)|Retorna o número de elementos em esse mapeamento.|  
|[CMapStringToOb::GetStartPosition](../Topic/CMapStringToOb::GetStartPosition.md)|Retorna a posição do primeiro elemento.|  
|[CMapStringToOb::HashKey](../Topic/CMapStringToOb::HashKey.md)|Calcula o valor de hash de uma chave especificada.|  
|[CMapStringToOb::InitHashTable](../Topic/CMapStringToOb::InitHashTable.md)|Inicializa o tabela de hash.|  
|[CMapStringToOb::IsEmpty](../Topic/CMapStringToOb::IsEmpty.md)|Testa a condição de mapa vazio\- \(elementos\).|  
|[CMapStringToOb::Lookup](../Topic/CMapStringToOb::Lookup.md)|Pesquisa um ponteiro vago com base na chave vaga do ponteiro.  O valor de ponteiro, não entidade que aponte para, é usado para comparação principal.|  
|[CMapStringToOb::LookupKey](../Topic/CMapStringToOb::LookupKey.md)|Retorna uma referência para a chave associada com o valor da chave especificado.|  
|[CMapStringToOb::RemoveAll](../Topic/CMapStringToOb::RemoveAll.md)|Remove todos os elementos de esse mapeamento.|  
|[CMapStringToOb::RemoveKey](../Topic/CMapStringToOb::RemoveKey.md)|Remove um elemento especificado por uma chave.|  
|[CMapStringToOb::SetAt](../Topic/CMapStringToOb::SetAt.md)|Insere um elemento no mapa; substitui um elemento existente se uma tecla correspondente for encontrada.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMapStringToOb::operator](../Topic/CMapStringToOb::operator.md)|Insere um elemento no mapa — substituição do operador para `SetAt`.|  
  
## Comentários  
 Uma vez que você inseriu um par de `CString`\- de`CObject*` \(elemento\) no mapa de forma eficiente, você pode recuperar ou exclua os pares usando uma cadeia de caracteres ou um valor de `CString` como uma chave.  Você também pode iterar todos os elementos no mapa.  
  
 Uma variável do tipo **POSIÇÃO** é usado para acesso alternativo de entrada em todas as variações de mapa.  Você pode usar **POSIÇÃO** “memoriza” uma entrada e iterar\-lo através do mapa.  Você pode pensar que essa interação é seqüencial pelo valor da chave; não é.  A seqüência de elementos recuperados é indefinida.  
  
 `CMapStringToOb` inserir a macro de `IMPLEMENT_SERIAL` para oferecer suporte a serialização e a despejo de seus elementos.  Cada elemento é serializado por sua vez se um mapa é armazenado em um arquivo, com o operador sobrecarregado de inserção \(**\<\<**\) ou com a função de membro de `Serialize`.  
  
 Se você precisar de um despejo diagnóstico dos elementos individuais no mapa \(o valor de `CString` e o conteúdo de `CObject` \), você deve definir o tamanho do contexto de um despejo a 1 ou maior.  
  
 Quando um objeto de `CMapStringToOb` é excluído, ou quando seus elementos são removidos, os objetos de `CString` e ponteiros de `CObject` são removidos.  Os objetos referenciados pelos ponteiros de `CObject` não serão destruídos.  
  
 A derivação da classe de mapa é semelhante à derivação da lista.  Consulte o artigo [coleções](../../mfc/collections.md) para uma ilustração de derivar de uma classe de lista de propósito especial.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CMapStringToOb`  
  
## Requisitos  
 **Cabeçalho:** afxcoll.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)   
 [Classe de CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)   
 [Classe de CMapStringToPtr](../Topic/CMapStringToPtr%20Class.md)   
 [Classe de CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)   
 [Classe de CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)   
 [Classe de CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)