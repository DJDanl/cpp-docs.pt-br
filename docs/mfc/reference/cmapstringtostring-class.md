---
title: Classe CMapStringToString | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMapStringToString
dev_langs:
- C++
helpviewer_keywords:
- collection classes, string mapping
- strings [C++], mapping
- strings [C++], class for mapping
- CMapStringToString class
ms.assetid: b45794c2-fe6b-4edb-a8ca-faa03b57b4a8
caps.latest.revision: 23
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 58ca2023d57c2865dadc8dfab304aab2fa39a96b
ms.lasthandoff: 02/25/2017

---
# <a name="cmapstringtostring-class"></a>Classe CMapStringToString
Oferece suporte a mapas de `CString` objetos chaveados por `CString` objetos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMapStringToString : public CObject  
```  
  
## <a name="members"></a>Membros  
 As funções de membro do `CMapStringToString` são semelhantes às funções de membro da classe [CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CMapStringToOb` para obter a função específica de membro. Ao ver um `CObject` ponteiro como um valor de retorno ou "saída" funciona como parâmetro, um ponteiro para substituir `char`. Ao ver um `CObject` ponteiro como um parâmetro de função "entrada", substitua um ponteiro para `char`.  
  
 `BOOL CMapStringToOb::Lookup(const char*<key>, CObject*&<rValue>) const;`  
  
 por exemplo, traduz para  
  
 `BOOL CMapStringToString::Lookup(LPCTSTR<key>, CString&<rValue>) const;`  
  
### <a name="public-structures"></a>Estruturas de públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMapStringToString::CPair](#cpair)|Uma estrutura aninhada que contém um valor de chave e o valor do objeto de cadeia de caracteres associado.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMapStringToOb::CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md#cmapstringtoob)|Construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMapStringToOb::GetCount](../../mfc/reference/cmapstringtoob-class.md#getcount)|Retorna o número de elementos neste mapa.|  
|[CMapStringToOb::GetHashTableSize](../../mfc/reference/cmapstringtoob-class.md#gethashtablesize)|Determina o número de elementos na tabela de hash.|  
|[CMapStringToOb::GetNextAssoc](../../mfc/reference/cmapstringtoob-class.md#getnextassoc)|Obtém o próximo elemento de iteração.|  
|[CMapStringToOb::GetSize](../../mfc/reference/cmapstringtoob-class.md#getsize)|Retorna o número de elementos neste mapa.|  
|[CMapStringToOb::GetStartPosition](../../mfc/reference/cmapstringtoob-class.md#getstartposition)|Retorna a posição do primeiro elemento.|  
|[CMapStringToOb::HashKey](../../mfc/reference/cmapstringtoob-class.md#hashkey)|Calcula o valor de hash de uma chave especificada.|  
|[CMapStringToOb::InitHashTable](../../mfc/reference/cmapstringtoob-class.md#inithashtable)|Inicializa a tabela de hash.|  
|[CMapStringToOb::IsEmpty](../../mfc/reference/cmapstringtoob-class.md#isempty)|Testa a condição de mapa vazio (sem elementos).|  
|[CMapStringToOb::Lookup](../../mfc/reference/cmapstringtoob-class.md#lookup)|Procura por um ponteiro nulo, com base na chave de ponteiro nulo. O valor do ponteiro, não a entidade a qual ele aponta, é usado para a comparação de chave.|  
|[CMapStringToOb::LookupKey](../../mfc/reference/cmapstringtoob-class.md#lookupkey)|Retorna uma referência para a chave associada com o valor da chave especificado.|  
|[CMapStringToString::PGetFirstAssoc](#pgetfirstassoc)|Obtém um ponteiro para o primeiro `CString` no mapa.|  
|[CMapStringToString::PGetNextAssoc](#pgetnextassoc)|Obtém um ponteiro para o próximo `CString` para iterar.|  
|[CMapStringToString::PLookup](#plookup)|Retorna um ponteiro para um `CString` cujo valor corresponde ao valor especificado.|  
|[CMapStringToOb::RemoveAll](../../mfc/reference/cmapstringtoob-class.md#removeall)|Remove todos os elementos a partir desse mapa.|  
|[CMapStringToOb::RemoveKey](../../mfc/reference/cmapstringtoob-class.md#removekey)|Remove um elemento especificado por uma chave.|  
|[CMapStringToOb::SetAt](../../mfc/reference/cmapstringtoob-class.md#setat)|Insere um elemento no mapa; substitui um elemento existente, se uma chave correspondente for encontrada.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[[CMapStringToOb::operator]](../../mfc/reference/cmapstringtoob-class.md#operator_at)|Insere um elemento no mapa — substituição de operador para `SetAt`.|  
  
## <a name="remarks"></a>Comentários  
 A `CMapStringToString` incorpora a macro `IMPLEMENT_SERIAL` para suportar serialização e despejo de seus elementos. Cada elemento é serializado por sua vez, se um mapa é armazenado em um arquivo, com a inserção sobrecarregada ( ** << **) operador ou com o `Serialize` função de membro.  
  
 Se for necessário um despejo de individuais `CString` -  `CString` elementos, você deve definir a profundidade do contexto do despejo como 1 ou maior.  
  
 Quando um `CMapStringToString` objeto é excluído, ou quando seus elementos são removidos, o `CString` objetos são removidos conforme apropriado.  
  
 Para obter mais informações sobre `CMapStringToString`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CMapStringToString`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcoll. h  
  
##  <a name="a-namecpaira--cmapstringtostringcpair"></a><a name="cpair"></a>CMapStringToString::CPair  
 Contém um valor de chave e o valor do objeto de cadeia de caracteres associado.  
  
### <a name="remarks"></a>Comentários  
 Essa é uma estrutura aninhada dentro da classe [CMapStringToString](../../mfc/reference/cmapstringtostring-class.md).  
  
 A estrutura é composta de dois campos:  
  
- **chave** o valor real do tipo de chave.  
  
- **valor** o valor do objeto associado.  
  
 Ele é usado para armazenar os valores de retorno de [CMapStringToString::PLookup](#plookup), [CMapStringToString::PGetFirstAssoc](#pgetfirstassoc), e [CMapStringToString::PGetNextAssoc](#pgetnextassoc).  
  
### <a name="example"></a>Exemplo  
  Para obter um exemplo de uso, consulte o exemplo para [CMapStringToString::PLookup](#plookup).  
  
##  <a name="a-namepgetfirstassoca--cmapstringtostringpgetfirstassoc"></a><a name="pgetfirstassoc"></a>CMapStringToString::PGetFirstAssoc  
 Retorna a primeira entrada do objeto de mapa.  
  
```  
const CPair* PGetFirstAssoc() const;

CPair* PGetFirstAssoc();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a primeira entrada no mapa; consulte [CMapStringToString::CPair](#cpair). Se o mapa estiver vazio, o valor é `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para retornar o primeiro elemento de um ponteiro no objeto de mapa.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#73;](../../mfc/codesnippet/cpp/cmapstringtostring-class_1.cpp)]  
  
##  <a name="a-namepgetnextassoca--cmapstringtostringpgetnextassoc"></a><a name="pgetnextassoc"></a>CMapStringToString::PGetNextAssoc  
 Recupera o elemento de mapa apontado por `pAssocRec`.  
  
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
 Chame esse método para iterar todos os elementos no mapa. Recuperar o primeiro elemento com uma chamada para `PGetFirstAssoc` e, em seguida, percorrer o mapa com sucessivas chamadas a `PGetNextAssoc`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMapStringToString::PGetFirstAssoc](#pgetfirstassoc).  
  
##  <a name="a-nameplookupa--cmapstringtostringplookup"></a><a name="plookup"></a>CMapStringToString::PLookup  
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
 Chame esse método para pesquisar um elemento do mapa com uma chave que corresponda exatamente a chave especificada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#74;](../../mfc/codesnippet/cpp/cmapstringtostring-class_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC COLETAR](../../visual-cpp-samples.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




