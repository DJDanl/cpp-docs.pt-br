---
title: "Classe de CMapStringToString | Microsoft Docs"
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
  - "CMapStringToString"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMapStringToString"
  - "classes de coleção, mapeamento de cadeias de caracteres"
  - "cadeias de caracteres [C++], classe para mapear"
  - "cadeias de caracteres [C++], mapear"
ms.assetid: b45794c2-fe6b-4edb-a8ca-faa03b57b4a8
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMapStringToString
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Mapas de suporte de objetos de `CString` fechadas por `CString` objeto.  
  
## Sintaxe  
  
```  
class CMapStringToString : public CObject  
```  
  
## Membros  
 As funções de membro de `CMapStringToString` são semelhantes às funções de membro da classe [CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md).  Devido a essa similaridade, você pode usar a documentação de referência de `CMapStringToOb` para específicos da função de membro.  Onde quer que você verá um ponteiro de `CObject` como um parâmetro de função do valor de retorno de “ou” saída, substitua um ponteiro para `char`.  Onde quer que você verá um ponteiro de `CObject` como um parâmetro de entrada “function”, substitua um ponteiro para `char`.  
  
 `BOOL CMapStringToOb::Lookup(const char*<key>, CObject*&<rValue>) const;`  
  
 por exemplo, converte a  
  
 `BOOL CMapStringToString::Lookup(LPCTSTR<key>, CString&<rValue>) const;`  
  
### Estruturas públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMapStringToString::CPair](../Topic/CMapStringToString::CPair.md)|Uma estrutura aninhada que contêm um valor da chave e o valor da cadeia de caracteres associada objeto.|  
  
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
|[CMapStringToString::PGetFirstAssoc](../Topic/CMapStringToString::PGetFirstAssoc.md)|Obtém um ponteiro para primeiro `CString` no mapa.|  
|[CMapStringToString::PGetNextAssoc](../Topic/CMapStringToString::PGetNextAssoc.md)|Obtém um ponteiro para `CString` seguir para iterar.|  
|[CMapStringToString::PLookup](../Topic/CMapStringToString::PLookup.md)|Retorna um ponteiro para `CString` cujo valor corresponde ao valor especificado.|  
|[CMapStringToOb::RemoveAll](../Topic/CMapStringToOb::RemoveAll.md)|Remove todos os elementos de esse mapeamento.|  
|[CMapStringToOb::RemoveKey](../Topic/CMapStringToOb::RemoveKey.md)|Remove um elemento especificado por uma chave.|  
|[CMapStringToOb::SetAt](../Topic/CMapStringToOb::SetAt.md)|Insere um elemento no mapa; substitui um elemento existente se uma tecla correspondente for encontrada.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMapStringToOb::operator](../Topic/CMapStringToOb::operator.md)|Insere um elemento no mapa — substituição do operador para `SetAt`.|  
  
## Comentários  
 `CMapStringToString` inserir a macro de `IMPLEMENT_SERIAL` para oferecer suporte a serialização e a despejo de seus elementos.  Cada elemento é serializado por sua vez se um mapa é armazenado em um arquivo, com o operador sobrecarregado de inserção \(**\<\<**\) ou com a função de membro de `Serialize`.  
  
 Se você precisar de um despejo `CString`individual \- os elementos de`CString` , você deve definir o tamanho do contexto de um despejo a 1 ou maior.  
  
 Quando um objeto de `CMapStringToString` é excluído, ou quando seus elementos são removidos, os objetos de `CString` são removidos conforme apropriado.  
  
 Para obter mais informações sobre `CMapStringToString`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CMapStringToString`  
  
## Requisitos  
 **Cabeçalho:** afxcoll.h  
  
## Consulte também  
 [O exemplo COLETA MFC](../../top/visual-cpp-samples.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)