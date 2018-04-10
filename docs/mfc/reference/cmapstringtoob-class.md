---
title: Classe CMapStringToOb | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- CMapStringToOb
- AFXCOLL/CMapStringToOb
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
ms.assetid: 09653980-b885-4f3a-8594-0aeb7f94c601
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1a840677819710247e73aa8e3bcb904be756f852
ms.sourcegitcommit: 0523c88b24d963c33af0529e6ba85ad2c6ee5afb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/10/2018
---
# <a name="cmapstringtoob-class"></a>Classe CMapStringToOb
Uma classe de coleção de dicionário que mapeia exclusivo `CString` objetos `CObject` ponteiros.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMapStringToOb : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMapStringToOb::CMapStringToOb](#cmapstringtoob)|Construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMapStringToOb::GetCount](#getcount)|Retorna o número de elementos no mapa.|  
|[CMapStringToOb::GetHashTableSize](#gethashtablesize)|Determina o número atual de elementos na tabela de hash.|  
|[CMapStringToOb::GetNextAssoc](#getnextassoc)|Obtém o próximo elemento de iteração.|  
|[CMapStringToOb::GetSize](#getsize)|Retorna o número de elementos no mapa.|  
|[CMapStringToOb::GetStartPosition](#getstartposition)|Retorna a posição do primeiro elemento.|  
|[CMapStringToOb::HashKey](#hashkey)|Calcula o valor de hash de uma chave especificada.|  
|[CMapStringToOb::InitHashTable](#inithashtable)|Inicializa a tabela de hash.|  
|[CMapStringToOb::IsEmpty](#isempty)|Testes para a condição de mapa vazio (nenhum elemento).|  
|[CMapStringToOb::Lookup](#lookup)|Procura um ponteiro nulo, com base na chave de ponteiro nulo. O valor do ponteiro, não a entidade que ele aponte para, é usado para a comparação de chave.|  
|[CMapStringToOb::LookupKey](#lookupkey)|Retorna uma referência para a chave associada com o valor da chave especificado.|  
|[CMapStringToOb::RemoveAll](#removeall)|Remove todos os elementos esse mapa.|  
|[CMapStringToOb::RemoveKey](#removekey)|Remove um elemento especificado por uma chave.|  
|[CMapStringToOb::SetAt](#setat)|Insere um elemento no mapa; substitui um elemento existente se for encontrada uma chave correspondente.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMapStringToOb::operator [ ]](#operator_at)|Insere um elemento no mapa — substituição de operador para `SetAt`.|  
  
## <a name="remarks"></a>Comentários  
 Depois que você inseriu um `CString` -  `CObject*` par (elemento a) para o mapa com eficiência você pode recuperar ou excluir o par usando uma cadeia de caracteres ou um `CString` valor como uma chave. Você também pode iterar por todos os elementos no mapa.  
  
 Uma variável do tipo **posição** é usada para acesso de entrada alternativo em todas as variações de mapa. Você pode usar um **posição** "lembrar" uma entrada e percorrer o mapa. Você pode achar que essa iteração é sequencial pelo valor de chave; não é. A sequência de elementos recuperados é indeterminada.  
  
 A `CMapStringToOb` incorpora a macro `IMPLEMENT_SERIAL` para suportar serialização e despejo de seus elementos. Cada elemento é serializado por sua vez, se um mapa é armazenado para um arquivo, com a inserção sobrecarregada ( **<<**) operador ou com o `Serialize` função de membro.  
  
 Se você precisa de um despejo de diagnóstico dos elementos individuais no mapa (o `CString` valor e o `CObject` conteúdo), você deve definir a profundidade do contexto do despejo como 1 ou maior.  
  
 Quando um `CMapStringToOb` objeto é excluído, ou quando seus elementos são removidos, o `CString` objetos e o `CObject` ponteiros são removidos. Os objetos referenciados pelo `CObject` ponteiros não são destruídos.  
  
 Derivação de classe de mapa é semelhante a derivação de lista. Consulte o artigo [coleções](../../mfc/collections.md) para obter uma ilustração de derivação de uma classe especial de lista.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CMapStringToOb`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcoll.h  
  
##  <a name="cmapstringtoob"></a>  CMapStringToOb::CMapStringToOb  
 Constrói um vazio `CString`- para - `CObject*` mapa.  
  
```  
CMapStringToOb(INT_PTR nBlockSize = 10);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBlockSize`  
 Especifica a granularidade de alocação de memória para estender o mapa.  
  
### <a name="remarks"></a>Comentários  
 À medida que cresce o mapa, a memória é alocada em unidades de `nBlockSize` entradas.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às **CMapStringToOb:: CMapStringToOb**.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**CMapPtrToPtr( INT_PTR** `nBlockSize` **= 10 );**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**CMapPtrToWord( INT_PTR** `nBlockSize` **= 10 );**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**CMapStringToPtr( INT_PTR** `nBlockSize` **= 10 );**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**CMapStringToString( INT_PTR** `nBlockSize` **= 10 );**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**CMapWordToOb( INT_PTR** `nBlockSize` **= 10 );**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**MapWordToPtr( INT_PTR** `nBlockSize` **= 10 );**|  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#63](../../mfc/codesnippet/cpp/cmapstringtoob-class_1.cpp)]  
  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
##  <a name="getcount"></a>  CMapStringToOb::GetCount  
 Determina o número de elementos no mapa.  
  
```  
INT_PTR GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos no mapa.  
  
### <a name="remarks"></a>Comentários  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::GetCount`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**INT_PTR GetCount( ) const;**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**INT_PTR GetCount( ) const;**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**INT_PTR GetCount( ) const;**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**INT_PTR GetCount( ) const;**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**INT_PTR GetCount( ) const;**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**INT_PTR GetCount( ) const;**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#64](../../mfc/codesnippet/cpp/cmapstringtoob-class_2.cpp)]  
  
##  <a name="gethashtablesize"></a>  CMapStringToOb::GetHashTableSize  
 Determina o número atual de elementos na tabela de hash.  
  
```  
UINT GetHashTableSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de elementos na tabela de hash.  
  
### <a name="remarks"></a>Comentários  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::GetHashTableSize`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**UINT GetHashTableSize( ) const;**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**UINT GetHashTableSize( ) const;**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**UINT GetHashTableSize( ) const;**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**UINT GetHashTableSize( ) const;**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**UINT GetHashTableSize( ) const;**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**UINT GetHashTableSize( ) const;**|  
  
##  <a name="getnextassoc"></a>  CMapStringToOb::GetNextAssoc  
 Recupera o elemento de mapa na *rNextPosition*, em seguida, atualiza *rNextPosition* para referir-se para o próximo elemento no mapa.  
  
```  
void GetNextAssoc(
    POSITION& rNextPosition,  
    CString& rKey,  
    CObject*& rValue) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *rNextPosition*  
 Especifica uma referência a um **posição** valor retornado pelo anterior **GetNextAssoc** ou **GetStartPosition** chamar.  
  
 *rKey*  
 Especifica a chave retornada do elemento recuperado (uma cadeia de caracteres).  
  
 *rValue*  
 Especifica o valor retornado do elemento recuperado (um **CObject** ponteiro). Consulte comentários para obter mais informações sobre esse parâmetro.  
  
### <a name="remarks"></a>Comentários  
 Essa função é mais útil para iterar através de todos os elementos no mapa. Observe que a sequência de posição não é necessariamente o mesmo que a sequência de valor de chave.  
  
 Se o elemento recuperado é o último no mapa, em seguida, o novo valor de *rNextPosition* é definido como **nulo**.  
  
 Para o *rValue* parâmetro, certifique-se de converter o tipo de objeto para **CObject\*&**, que é o que exige que o compilador, conforme mostrado no exemplo a seguir:  
  
 [!code-cpp[NVC_MFCCollections#65](../../mfc/codesnippet/cpp/cmapstringtoob-class_3.cpp)]  
  
 Isso não é verdade **GetNextAssoc** para mapas com base em modelos.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às **CMapStringToOb::GetNextAssoc**.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**void GetNextAssoc( POSITION&** *rNextPosition* **, void\*&** *rKey* **, void\*&** *rValue* **) const;**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**void GetNextAssoc( POSITION&** *rNextPosition* **, void\*&** *rKey* **, WORD&** *rValue* **) const;**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void GetNextAssoc( POSITION&** *rNextPosition* **, CString&** *rKey* **, void\*&** *rValue* **) const;**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**void GetNextAssoc( POSITION&** *rNextPosition* **, CString&** *rKey* **, CString&** *rValue* **) const;**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**void GetNextAssoc( POSITION&** *rNextPosition* **, WORD&** *rKey* **, CObject\*&** *rValue* **) const;**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void GetNextAssoc( POSITION&** *rNextPosition* **, WORD&** *rKey* **, void\*&** *rValue* **) const;**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#66](../../mfc/codesnippet/cpp/cmapstringtoob-class_4.cpp)]  
  
 Os resultados desse programa são da seguinte maneira:  
  
 `Lisa : a CAge at $4724 11`  
  
 `Marge : a CAge at $47A8 35`  
  
 `Homer : a CAge at $4766 36`  
  
 `Bart : a CAge at $45D4 13`  
  
##  <a name="getsize"></a>  CMapStringToOb::GetSize  
 Retorna o número de elementos do mapa.  
  
```  
INT_PTR GetSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens no mapa.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para recuperar o número de elementos no mapa.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::GetSize`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**INT_PTR GetSize( ) const;**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**INT_PTR GetSize( ) const;**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**INT_PTR GetSize( ) const;**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**INT_PTR GetSize( ) const;**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**INT_PTR GetSize( ) const;**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**INT_PTR GetSize( ) const;**|  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#67](../../mfc/codesnippet/cpp/cmapstringtoob-class_5.cpp)]  
  
##  <a name="getstartposition"></a>  CMapStringToOb::GetStartPosition  
 Inicia uma iteração de mapa, retornando um **posição** valor que pode ser passado para um `GetNextAssoc` chamar.  
  
```  
POSITION GetStartPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um **posição** valor que indica uma posição inicial para o mapa; de iteração ou **nulo** se o mapa estiver vazio.  
  
### <a name="remarks"></a>Comentários  
 A sequência de iteração não é previsível; Portanto, o "primeiro elemento no mapa" não tem nenhum significado especial.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::GetStartPosition`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**POSICIONAR GetStartPosition () const;**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**POSICIONAR GetStartPosition () const;**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**POSICIONAR GetStartPosition () const;**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**POSICIONAR GetStartPosition () const;**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**POSICIONAR GetStartPosition () const;**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**POSICIONAR GetStartPosition () const;**|  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMapStringToOb::GetNextAssoc](#getnextassoc).  
  
##  <a name="hashkey"></a>  CMapStringToOb::HashKey  
 Calcula o valor de hash de uma chave especificada.  
  
```  
UINT HashKey(LPCTSTR key) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave cujo valor de hash é calculado.  
  
### <a name="return-value"></a>Valor de retorno  
 Valor de hash da chave  
  
### <a name="remarks"></a>Comentários  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::HashKey`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**UINT HashKey( void\*** `key` **) const;**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**UINT HashKey( void\*** `key` **) const;**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**HashKey UINT (LPCTSTR** `key` **) const;**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**HashKey UINT (LPCTSTR** `key` **) const;**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**HashKey UINT (WORD** `key` **) const;**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**HashKey UINT (WORD** `key` **) const;**|  
  
##  <a name="inithashtable"></a>  CMapStringToOb::InitHashTable  
 Inicializa a tabela de hash.  
  
```  
void InitHashTable(
    UINT hashSize,  
    BOOL bAllocNow = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hashSize`  
 Número de entradas na tabela de hash.  
  
 `bAllocNow`  
 Se **TRUE**, aloca a tabela de hash na inicialização; caso contrário, a tabela é alocada quando necessário.  
  
### <a name="remarks"></a>Comentários  
 Para melhor desempenho, o tamanho da tabela de hash deve ser um número primo. Para minimizar colisões, o tamanho deve ser aproximadamente a 20 por cento maior que o maior conjunto de dados esperado.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::InitHashTable`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**void InitHashTable( UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE );**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**void InitHashTable( UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE );**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**void InitHashTable( UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE );**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void InitHashTable( UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE );**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**void InitHashTable( UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE );**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void InitHashTable( UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE );**|  
  
##  <a name="isempty"></a>  CMapStringToOb::IsEmpty  
 Determina se o mapa estiver vazio.  
  
```  
BOOL IsEmpty() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o mapa não contém elementos; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [RemoveAll](#removeall).  
  
### <a name="remarks"></a>Comentários  
 A tabela a seguir mostra outro membro funções que são semelhantes às **CMapStringToOb:: IsEmpty**.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**BOOL (de) de IsEmpty const;**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**BOOL (de) de IsEmpty const;**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**BOOL (de) de IsEmpty const;**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**BOOL (de) de IsEmpty const;**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**BOOL (de) de IsEmpty const;**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**BOOL (de) de IsEmpty const;**|  
  
##  <a name="lookup"></a>  CMapStringToOb::Lookup  
 Retorna um `CObject` ponteiro com base em um `CString` valor.  
  
```  
BOOL Lookup(
    LPCTSTR key,  
    CObject*& rValue) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 Especifica a chave de cadeia de caracteres que identifica o elemento a ser pesquisado.  
  
 `rValue`  
 Especifica o valor do elemento up pesquisados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o elemento foi encontrado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 `Lookup` usa um algoritmo de hash para localizar rapidamente o elemento do mapa com uma chave que corresponda exatamente ( `CString` valor).  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::LookUp`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**Pesquisa de BOOL (void\***  `key` **, void\* &**  `rValue` **) const;**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**Pesquisa de BOOL (void\***  `key` **, WORD &** `rValue` **) const;**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**BOOL Lookup( LPCTSTR** `key` **, void\*&** `rValue` **) const;**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**Pesquisa de BOOL (LPCTSTR** `key` **, CString &** `rValue` **) const;**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**Pesquisa de BOOL (WORD** `key` **, CObject\* &**  `rValue` **) const;**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**Pesquisa de BOOL (WORD** `key` **, void\* &**  `rValue` **) const;**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#68](../../mfc/codesnippet/cpp/cmapstringtoob-class_6.cpp)]  
  
##  <a name="lookupkey"></a>  CMapStringToOb::LookupKey  
 Retorna uma referência para a chave associada com o valor da chave especificado.  
  
```  
BOOL LookupKey(
    LPCTSTR key,  
    LPCTSTR& rKey) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 Especifica a chave de cadeia de caracteres que identifica o elemento a ser pesquisado.  
  
 `rKey`  
 A referência para a chave associada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a chave foi encontrada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Usando uma referência a uma chave não é seguro se usado após o elemento associado foi removido do mapa ou depois que o mapa foi destruído.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às **CMapStringToOb:: LookupKey**.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**BOOL LookupKey (LPCTSTR** `key` **, LPCTSTR &** `rKey` **) const;**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**BOOL LookupKey (LPCTSTR** `key` **, LPCTSTR &** `rKey` **) const;**|  
  
##  <a name="operator_at"></a>  CMapStringToOb::operator [ ]  
 Um substituto conveniente para o `SetAt` função de membro.  
  
```  
CObject*& operator[ ](lpctstr key);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um ponteiro para um `CObject` objeto; ou **nulo** se o mapa estiver vazio ou `key` está fora do intervalo.  
  
### <a name="remarks"></a>Comentários  
 Assim, ele pode ser usado somente no lado esquerdo de uma instrução de atribuição (um l-value). Se não houver nenhum elemento do mapa com a chave especificada, um novo elemento é criado.  
  
 Não há nenhuma "direita" (r) equivalente ao operador porque há uma possibilidade de que uma chave não pode ser encontrada no mapa. Use o `Lookup` a função de membro para recuperação do elemento.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às **[CMapStringToOb::operator]**.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**void\*& operator[](void\*** `key` **\);**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**[] Do operador & WORD (void\***  `key`  **\);**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void\*& operator[](lpctstr** `key` **\);**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**CString& operator[](lpctstr** `key` **\);**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**CObject\*& operador [] (word** `key`  **\);**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void\*& operator[](word** `key` **\);**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#72](../../mfc/codesnippet/cpp/cmapstringtoob-class_7.cpp)]  
  
 Os resultados desse programa são da seguinte maneira:  
  
 `Operator [] example: A CMapStringToOb with 2 elements`  
  
 `[Lisa] = a CAge at $4A02 11`  
  
 `[Bart] = a CAge at $497E 13`  
  
##  <a name="removeall"></a>  CMapStringToOb::RemoveAll  
 Remove todos os elementos deste mapa e destrói o `CString` objetos de chave.  
  
```  
void RemoveAll();
```  
  
### <a name="remarks"></a>Comentários  
 O `CObject` objetos referenciados por cada chave não são destruídos. O `RemoveAll` função pode causar vazamentos de memória se não verifique se referenciado `CObject` os objetos são destruídos.  
  
 A função funciona corretamente se o mapa já estiver vazio.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::RemoveAll`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**void RemoveAll( );**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**void RemoveAll( );**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void RemoveAll( );**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**void RemoveAll( );**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**void RemoveAll( );**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void RemoveAll( );**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#69](../../mfc/codesnippet/cpp/cmapstringtoob-class_8.cpp)]  
  
##  <a name="removekey"></a>  CMapStringToOb::RemoveKey  
 Procura a entrada do mapa correspondente à chave fornecida; em seguida, se a chave for encontrada, remove a entrada.  
  
```  
BOOL RemoveKey(LPCTSTR key);
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 Especifica a cadeia de caracteres usada para pesquisa de mapa.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a entrada foi encontrada e removida com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Isso pode causar vazamentos de memória se o `CObject` objeto não é excluído em outro lugar.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::RemoveKey`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**BOOL RemoveKey (void\***  `key` **);**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**BOOL RemoveKey (void\***  `key` **);**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**BOOL RemoveKey( LPCTSTR** `key` **);**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**BOOL RemoveKey( LPCTSTR** `key` **);**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**BOOL RemoveKey (WORD** `key` **);**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**BOOL RemoveKey (WORD** `key` **);**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#70](../../mfc/codesnippet/cpp/cmapstringtoob-class_9.cpp)]  
  
 Os resultados desse programa são da seguinte maneira:  
  
 `RemoveKey example: A CMapStringToOb with 3 elements`  
  
 `[Marge] = a CAge at $49A0 35`  
  
 `[Homer] = a CAge at $495E 36`  
  
 `[Bart] = a CAge at $4634 13`  
  
##  <a name="setat"></a>  CMapStringToOb::SetAt  
 O principal meio inserir um elemento em um mapa.  
  
```  
void SetAt(
    LPCTSTR key,  
    CObject* newValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 Especifica a cadeia de caracteres que é a chave do novo elemento.  
  
 `newValue`  
 Especifica o `CObject` ponteiro é o valor do novo elemento.  
  
### <a name="remarks"></a>Comentários  
 Primeiro, a chave é procurada. Se a chave for encontrada, o valor correspondente é alterado; Caso contrário, é criado um novo elemento de chave-valor.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::SetAt`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**void SetAt( void\*** `key` **, void\*** `newValue` **);**|  
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**void SetAt( void\*** `key` **, WORD** `newValue` **);**|  
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void SetAt( LPCTSTR** `key` **, void\*** `newValue` **);**|  
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**void SetAt( LPCTSTR** `key` **, LPCTSTR** `newValue` **);**|  
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**void SetAt( WORD** `key` **, CObject\*** `newValue` **);**|  
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void SetAt( WORD** `key` **, void\*** `newValue` **);**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#71](../../mfc/codesnippet/cpp/cmapstringtoob-class_10.cpp)]  
  
 Os resultados desse programa são da seguinte maneira:  
  
 `before Lisa's birthday: A CMapStringToOb with 2 elements`  
  
 `[Lisa] = a CAge at $493C 11`  
  
 `[Bart] = a CAge at $4654 13`  
  
 `after Lisa's birthday: A CMapStringToOb with 2 elements`  
  
 `[Lisa] = a CAge at $49C0 12`  
  
 `[Bart] = a CAge at $4654 13`  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)   
 [Classe CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)   
 [Classe CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)   
 [Classe CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)   
 [Classe CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)   
 [Classe CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)
