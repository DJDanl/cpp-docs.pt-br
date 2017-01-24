---
title: "Classe de CMap | Microsoft Docs"
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
  - "CMap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMap"
  - "classes de coleção, mapeamento de dicionário"
  - "classe de mapeamento de dicionário"
ms.assetid: 640a45ab-0993-4def-97ec-42cc78eb10b9
caps.latest.revision: 24
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMap
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma classe de coleção de dicionário que mapeia chaves exclusivas para valores.  
  
## Sintaxe  
  
```  
template< class KEY, class ARG_KEY, class VALUE, class ARG_VALUE >class CMap : public CObject  
```  
  
#### Parâmetros  
 `KEY`  
 Classe de objeto usado como a chave do mapa.  
  
 `ARG` *\_* `KEY`  
 Tipo de dados usado para argumentos de `KEY` ; geralmente uma referência a `KEY`.  
  
 `VALUE`  
 Classe de objeto armazenado no mapa.  
  
 `ARG` *\_* `VALUE`  
 Tipo de dados usado para argumentos de `VALUE` ; geralmente uma referência a `VALUE`.  
  
## Membros  
  
### Estruturas públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMap::CPair](../Topic/CMap::CPair.md)|Uma estrutura aninhada que contém um valor da chave e o valor do objeto associado.|  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMap::CMap](../Topic/CMap::CMap.md)|Constrói uma coleção que mapeia chaves para valores.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMap::GetCount](../Topic/CMap::GetCount.md)|Retorna o número de elementos em esse mapeamento.|  
|[CMap::GetHashTableSize](../Topic/CMap::GetHashTableSize.md)|Retorna o número de elementos na tabela hash.|  
|[CMap::GetNextAssoc](../Topic/CMap::GetNextAssoc.md)|Obtém o próximo elemento para iterar.|  
|[CMap::GetSize](../Topic/CMap::GetSize.md)|Retorna o número de elementos em esse mapeamento.|  
|[CMap::GetStartPosition](../Topic/CMap::GetStartPosition.md)|Retorna a posição do primeiro elemento.|  
|[CMap::InitHashTable](../Topic/CMap::InitHashTable.md)|Inicializa o hash e especifique seu tamanho.|  
|[CMap::IsEmpty](../Topic/CMap::IsEmpty.md)|Testa a condição de mapa vazio\- \(elementos\).|  
|[CMap::Lookup](../Topic/CMap::Lookup.md)|Pesquisa o valor mapeado para uma determinada chave.|  
|[CMap::PGetFirstAssoc](../Topic/CMap::PGetFirstAssoc.md)|Retorna um ponteiro para o primeiro elemento.|  
|[CMap::PGetNextAssoc](../Topic/CMap::PGetNextAssoc.md)|Obtém um ponteiro para o próximo elemento para iterar.|  
|[CMap::PLookup](../Topic/CMap::PLookup.md)|Retorna um ponteiro a uma chave cujo valor corresponde ao valor especificado.|  
|[CMap::RemoveAll](../Topic/CMap::RemoveAll.md)|Remove todos os elementos de esse mapeamento.|  
|[CMap::RemoveKey](../Topic/CMap::RemoveKey.md)|Remove um elemento especificado por uma chave.|  
|[CMap::SetAt](../Topic/CMap::SetAt.md)|Insere um elemento no mapa; substitui um elemento existente se uma tecla correspondente for encontrada.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMap::operator](../Topic/CMap::operator.md)|Insere um elemento no mapa — substituição do operador para `SetAt`.|  
  
## Comentários  
 Uma vez que você inseriu um par chave\-valor \(elemento\) no mapa de forma eficiente, você pode recuperar ou exclua os pares usando a chave para acessá\-lo.  Você também pode iterar todos os elementos no mapa.  
  
 Uma variável do tipo **POSIÇÃO** é usado para acesso alternativo as entradas.  Você pode usar **POSIÇÃO** “memoriza” uma entrada e iterar\-lo através do mapa.  Você pode pensar que essa interação é seqüencial pelo valor da chave; não é.  A seqüência de elementos recuperados é indefinida.  
  
 Determinadas funções de membro de essa classe chamam funções auxiliares globais que devem ser personalizadas para a maioria dos usos da classe de `CMap` .  Consulte [Auxiliares de classe de coleção](../../mfc/reference/collection-class-helpers.md) na seção de macros e de Globais de `MFC``Reference`.  
  
 `CMap` substitui [CObject::Serialize](../Topic/CObject::Serialize.md) para oferecer suporte a serialização e a despejo de seus elementos.  Se um mapa é armazenado em um arquivo usando `Serialize`neutro, cada elemento do mapa é serializado por sua vez.  A implementação padrão de função auxiliar de `SerializeElements` faz uma gravação bit a bit.  Para obter informações sobre serialização da coleção de itens do ponteiro derivados de `CObject` ou outros tipos definidos pelo usuário, consulte [Como fazer uma coleção fortemente tipada](../../mfc/how-to-make-a-type-safe-collection.md).  
  
 Se você precisar de um despejo diagnóstico dos elementos individuais no mapa \(as chaves e valores\), você deve definir o tamanho do contexto de um despejo a 1 ou maior.  
  
 Quando um objeto de `CMap` é excluído, ou quando seus elementos são removidos, as chaves e valores ambas são removidos.  
  
 A derivação da classe de mapa é semelhante à derivação da lista.  Consulte o artigo [coleções](../../mfc/collections.md) para uma ilustração de derivar de uma classe de lista de propósito especial.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CMap`  
  
## Requisitos  
 **Cabeçalho:** afxtempl.h  
  
## Consulte também  
 [O exemplo COLETA MFC](../../top/visual-cpp-samples.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)