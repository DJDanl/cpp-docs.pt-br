---
title: Classe CMapStringToString | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMapStringToString
- AFXCOLL/CMapStringToString
- AFXCOLL/CMapStringToString::CPair
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
- AFXCOLL/CMapStringToString::PGetFirstAssoc
- AFXCOLL/CMapStringToString::PGetNextAssoc
- AFXCOLL/CMapStringToString::PLookup
- AFXCOLL/CMapStringToOb::RemoveAll
- AFXCOLL/CMapStringToOb::RemoveKey
- AFXCOLL/CMapStringToOb::SetAt
dev_langs: C++
helpviewer_keywords:
- CMapStringToString [MFC], CPair
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
- CMapStringToString [MFC], PGetFirstAssoc
- CMapStringToString [MFC], PGetNextAssoc
- CMapStringToString [MFC], PLookup
- CMapStringToOb [MFC], RemoveAll
- CMapStringToOb [MFC], RemoveKey
- CMapStringToOb [MFC], SetAt
ms.assetid: b45794c2-fe6b-4edb-a8ca-faa03b57b4a8
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 142a000b5521458e3bdace8f840295efd07209fc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmapstringtostring-class"></a>Classe CMapStringToString
Dá suporte a mapas de `CString` objetos chaveados `CString` objetos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMapStringToString : public CObject  
```  
  
## <a name="members"></a>Membros  
 As funções de membro de `CMapStringToString` são semelhantes às funções de membro da classe [CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CMapStringToOb` para obter a função específica de membro. Sempre que você vê um `CObject` ponteiro como parâmetro de função de um valor de retorno ou "saída" substituir um ponteiro para `char`. Sempre que você vê um `CObject` ponteiro como um parâmetro de função "entrada", substitua um ponteiro para `char`.  
  
 `BOOL CMapStringToOb::Lookup(const char*<key>, CObject*&<rValue>) const;`  
  
 por exemplo, traduz para  
  
 `BOOL CMapStringToString::Lookup(LPCTSTR<key>, CString&<rValue>) const;`  
  
### <a name="public-structures"></a>Estruturas públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMapStringToString::CPair](#cpair)|Uma estrutura aninhada que contém um valor de chave e o valor do objeto de cadeia de caracteres associada.|  
  
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
|[CMapStringToString::PGetFirstAssoc](#pgetfirstassoc)|Obtém um ponteiro para o primeiro `CString` no mapa.|  
|[CMapStringToString::PGetNextAssoc](#pgetnextassoc)|Obtém um ponteiro para a próxima `CString` para iteração.|  
|[CMapStringToString::PLookup](#plookup)|Retorna um ponteiro para um `CString` cujo valor corresponde ao valor especificado.|  
|[CMapStringToOb::RemoveAll](../../mfc/reference/cmapstringtoob-class.md#removeall)|Remove todos os elementos esse mapa.|  
|[CMapStringToOb::RemoveKey](../../mfc/reference/cmapstringtoob-class.md#removekey)|Remove um elemento especificado por uma chave.|  
|[CMapStringToOb::SetAt](../../mfc/reference/cmapstringtoob-class.md#setat)|Insere um elemento no mapa; substitui um elemento existente se for encontrada uma chave correspondente.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[[CMapStringToOb::operator]](../../mfc/reference/cmapstringtoob-class.md#operator_at)|Insere um elemento no mapa — substituição de operador para `SetAt`.|  
  
## <a name="remarks"></a>Comentários  
 A `CMapStringToString` incorpora a macro `IMPLEMENT_SERIAL` para suportar serialização e despejo de seus elementos. Cada elemento é serializado por sua vez, se um mapa é armazenado para um arquivo, com a inserção sobrecarregada (  **<<** ) operador ou com o `Serialize` função de membro.  
  
 Se você precisar de um despejo do indivíduo `CString` -  `CString` elementos, você deve definir a profundidade do contexto de despejo para 1 ou superior.  
  
 Quando um `CMapStringToString` objeto é excluído, ou quando seus elementos são removidos, o `CString` objetos são removidos conforme apropriado.  
  
 Para obter mais informações sobre `CMapStringToString`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CMapStringToString`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcoll.h  
  
##  <a name="cpair"></a>CMapStringToString::CPair  
 Contém um valor de chave e o valor do objeto de cadeia de caracteres associada.  
  
### <a name="remarks"></a>Comentários  
 Essa é uma estrutura aninhada dentro da classe [CMapStringToString](../../mfc/reference/cmapstringtostring-class.md).  
  
 A estrutura é composta de dois campos:  
  
- **chave** o valor real do tipo de chave.  
  
- **valor** o valor do objeto associado.  
  
 Ele é usado para armazenar os valores de retorno de [CMapStringToString::PLookup](#plookup), [CMapStringToString::PGetFirstAssoc](#pgetfirstassoc), e [CMapStringToString::PGetNextAssoc](#pgetnextassoc).  
  
### <a name="example"></a>Exemplo  
  Para obter um exemplo de uso, consulte o exemplo para [CMapStringToString::PLookup](#plookup).  
  
##  <a name="pgetfirstassoc"></a>CMapStringToString::PGetFirstAssoc  
 Retorna a primeira entrada do objeto de mapa.  
  
```  
const CPair* PGetFirstAssoc() const;

CPair* PGetFirstAssoc();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a primeira entrada no mapa; consulte [CMapStringToString::CPair](#cpair). Se o mapa estiver vazio, o valor será `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para retornar um ponteiro o primeiro elemento no objeto map.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#73](../../mfc/codesnippet/cpp/cmapstringtostring-class_1.cpp)]  
  
##  <a name="pgetnextassoc"></a>CMapStringToString::PGetNextAssoc  
 Recupera o elemento de mapa apontado pelo `pAssocRec`.  
  
```  
const CPair *PGetNextAssoc(const CPair* pAssoc) const;  
  
CPair *PGetNextAssoc(const CPair* pAssoc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pAssoc*  
 Aponta para uma entrada de mapa retornada pelo anterior [PGetNextAssoc](#pgetnextassoc) ou [PGetFirstAssoc](#pgetfirstassoc) chamar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a próxima entrada no mapa; consulte [CMapStringToString::CPair](#cpair). Se o elemento é o último no mapa, o valor será **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para iterar por todos os elementos no mapa. Recuperar o primeiro elemento com uma chamada para `PGetFirstAssoc` e, em seguida, percorrer o mapa com as chamadas sucessivas para `PGetNextAssoc`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CMapStringToString::PGetFirstAssoc](#pgetfirstassoc).  
  
##  <a name="plookup"></a>CMapStringToString::PLookup  
 Procura o valor mapeado para uma determinada chave.  
  
```  
const CPair* PLookup(LPCTSTR key) const;

CPair* PLookup(LPCTSTR key);
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 Um ponteiro para a chave para o elemento a ser procurado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a chave especificada.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para pesquisar um elemento do mapa com uma chave que coincide com a chave especificada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#74](../../mfc/codesnippet/cpp/cmapstringtostring-class_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC COLETAR](../../visual-cpp-samples.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



