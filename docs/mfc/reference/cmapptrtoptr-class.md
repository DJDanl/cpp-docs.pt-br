---
title: "Classe de CMapPtrToPtr | Microsoft Docs"
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
  - "CMapPtrToPtr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMapPtrToPtr"
  - "classes de coleção, mapeamento de ponteiro"
  - "classe de mapeamento de ponteiro"
ms.assetid: 23cbbaec-9d64-48f2-92ae-5e24fa64b926
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMapPtrToPtr
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Mapas de suporte de ponteiros vagos fechadas por ponteiros vagos.  
  
## Sintaxe  
  
```  
class CMapPtrToPtr : public CObject  
```  
  
## Membros  
 As funções de membro de `CMapPtrToPtr` são semelhantes às funções de membro da classe [CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md).  Devido a essa similaridade, você pode usar a documentação de referência de `CMapStringToOb` para específicos da função de membro.  Onde quer que você verá um ponteiro de `CObject` como um ou um valor de retorno da função, substitua um ponteiro para `void`.  Onde quer que você vê `CString` ou um ponteiro de **const** a `char` como um ou um valor de retorno da função, substitua um ponteiro para `void`.  
  
 `BOOL CMapStringToOb::Lookup( const char* <key>,`  
  
 `CObject*& <rValue> ) const;`  
  
 por exemplo, converte a  
  
 `BOOL CMapPtrToPtr::Lookup( void* <key>, void*& <rValue> ) const;`  
  
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
 `CMapPtrToPtr` inserir a macro de `IMPLEMENT_DYNAMIC` para oferecer suporte ao acesso do tipo em tempo de execução e o despejo a `CDumpContext` de um objeto.  Se você precisar de um despejo dos elementos individuais de mapa \(valores de ponteiro\), você deve definir o tamanho do contexto de um despejo a 1 ou maior.  
  
 Mapas de Ponteiro\-à\- ponteiro não podem ser serializados.  
  
 Quando um objeto de `CMapPtrToPtr` é excluído, ou quando seus elementos são removidos, somente os ponteiros são removidos, não as entidades que referenciam.  
  
 Para obter mais informações sobre `CMapPtrToPtr`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CMapPtrToPtr`  
  
## Requisitos  
 **Cabeçalho:** afxcoll.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)