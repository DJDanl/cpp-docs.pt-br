---
title: Classe CMapWordToOb | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMapWordToOb
- AFXCOLL/CMapWordToOb
- AFXCOLL/CMapStringToOb::CMapStringToOb
- AFXCOLL/CMapStringToOb::GetCount
- AFXCOLL/CMapStringToOb::GetHashTableSize
- AFXCOLL/CMapStringToOb::GetNextAssoc
- AFXCOLL/CMapStringToOb::GetSize
- AFXCOLL/CMapStringToOb::GetStartPosition
- AFXCOLL/CMapStringToOb::HashKey
- AFXCOLL/CMapStringToOb::InitHashTable
- AFXCOLL/CMapStringToOb::IsEmpty
- AFXCOLL/CMapStringToOb::Lookup
- AFXCOLL/CMapStringToOb::LookupKey
- AFXCOLL/CMapStringToOb::RemoveAll
- AFXCOLL/CMapStringToOb::RemoveKey
- AFXCOLL/CMapStringToOb::SetAt
dev_langs:
- C++
helpviewer_keywords:
- CMapStringToOb [MFC], CMapStringToOb
- CMapStringToOb [MFC], GetCount
- CMapStringToOb [MFC], GetHashTableSize
- CMapStringToOb [MFC], GetNextAssoc
- CMapStringToOb [MFC], GetSize
- CMapStringToOb [MFC], GetStartPosition
- CMapStringToOb [MFC], HashKey
- CMapStringToOb [MFC], InitHashTable
- CMapStringToOb [MFC], IsEmpty
- CMapStringToOb [MFC], Lookup
- CMapStringToOb [MFC], LookupKey
- CMapStringToOb [MFC], RemoveAll
- CMapStringToOb [MFC], RemoveKey
- CMapStringToOb [MFC], SetAt
ms.assetid: 9c9bcd76-456f-4cf9-b03c-dd28b49d5e4f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d358e256e28ea61c9b9c287429dfdfcb7b1435c6
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37041825"
---
# <a name="cmapwordtoob-class"></a>Classe CMapWordToOb
Dá suporte a mapas de `CObject` ponteiros chaveados palavras de 16 bits.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMapWordToOb : public CObject  
```  
  
## <a name="members"></a>Membros  
 As funções de membro de `CMapWordToOb` são semelhantes às funções de membro da classe [CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CMapStringToOb` para obter a função específica de membro. Sempre que você vê um `CString` ou um **const** ponteiro para **char** como um valor de retorno ou parâmetro de função, substitua **WORD**.  
  
 `BOOL CMapStringToOb::Lookup( const char* <key>,`  
  
 `CObject*& <rValue> ) const;`  
  
 por exemplo, traduz para  
  
 `BOOL CMapWordToOb::Lookup( WORD <key>, CObject*& <rValue> ) const;`  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMapStringToOb::CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md#cmapstringtoob)|Construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMapStringToOb::GetCount](../../mfc/reference/cmapstringtoob-class.md#getcount)|Retorna o número de elementos no mapa.|  
|[CMapStringToOb::GetHashTableSize](../../mfc/reference/cmapstringtoob-class.md#gethashtablesize)|Determina o número atual de elementos na tabela de hash.|  
|[CMapStringToOb::GetNextAssoc](../../mfc/reference/cmapstringtoob-class.md#getnextassoc)|Obtém o próximo elemento de iteração.|  
|[CMapStringToOb::GetSize](../../mfc/reference/cmapstringtoob-class.md#getsize)|Retorna o número de elementos no mapa.|  
|[CMapStringToOb::GetStartPosition](../../mfc/reference/cmapstringtoob-class.md#getstartposition)|Retorna a posição do primeiro elemento.|  
|[CMapStringToOb::HashKey](../../mfc/reference/cmapstringtoob-class.md#hashkey)|Calcula o valor de hash de uma chave especificada.|  
|[CMapStringToOb::InitHashTable](../../mfc/reference/cmapstringtoob-class.md#inithashtable)|Inicializa a tabela de hash.|  
|[CMapStringToOb::IsEmpty](../../mfc/reference/cmapstringtoob-class.md#isempty)|Testes para a condição de mapa vazio (nenhum elemento).|  
|[CMapStringToOb::Lookup](../../mfc/reference/cmapstringtoob-class.md#lookup)|Procura um ponteiro nulo, com base na chave de ponteiro nulo. O valor do ponteiro, não a entidade que ele aponte para, é usado para a comparação de chave.|  
|[CMapStringToOb::LookupKey](../../mfc/reference/cmapstringtoob-class.md#lookupkey)|Retorna uma referência para a chave associada com o valor da chave especificado.|  
|[CMapStringToOb::RemoveAll](../../mfc/reference/cmapstringtoob-class.md#removeall)|Remove todos os elementos esse mapa.|  
|[CMapStringToOb::RemoveKey](../../mfc/reference/cmapstringtoob-class.md#removekey)|Remove um elemento especificado por uma chave.|  
|[CMapStringToOb::SetAt](../../mfc/reference/cmapstringtoob-class.md#setat)|Insere um elemento no mapa; substitui um elemento existente se for encontrada uma chave correspondente.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[[CMapStringToOb::operator]](../../mfc/reference/cmapstringtoob-class.md#operator_at)|Insere um elemento no mapa — substituição de operador para `SetAt`.|  
  
## <a name="remarks"></a>Comentários  
 A `CMapWordToOb` incorpora a macro `IMPLEMENT_SERIAL` para suportar serialização e despejo de seus elementos. Cada elemento é serializado por sua vez, se um mapa é armazenado para um arquivo, com a inserção sobrecarregada ( **<<**) operador ou com o `Serialize` função de membro.  
  
 Se você precisar de um despejo do indivíduo **WORD** -  `CObject` elementos, você deve definir a profundidade do contexto de despejo para 1 ou superior.  
  
 Quando um `CMapWordToOb` objeto é excluído, ou quando seus elementos são removidos, o `CObject` ponteiros são removidos. Os objetos referenciados pelo `CObject` ponteiros não são destruídos.  
  
 Para obter mais informações sobre `CMapWordToOb`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CMapWordToOb`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcoll.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



