---
title: Classe COleSafeArray | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleSafeArray
dev_langs:
- C++
helpviewer_keywords:
- COleSafeArray class
- arrays [C++], safe
- safe arrays
- ODBC, safe arrays
ms.assetid: f45a5224-5f48-40ec-9ddd-287ef9740150
caps.latest.revision: 22
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
ms.openlocfilehash: 3cb6fa49e3adf7e14c34baf7feb64d12e54f2758
ms.lasthandoff: 02/25/2017

---
# <a name="colesafearray-class"></a>Classe COleSafeArray
Uma classe para trabalhar com matrizes de tipo arbitrário e dimensão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleSafeArray : public tagVARIANT  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleSafeArray::COleSafeArray](#colesafearray)|Constrói um objeto `COleSafeArray`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleSafeArray::AccessData](#accessdata)|Recupera um ponteiro para os dados de matriz.|  
|[COleSafeArray::AllocData](#allocdata)|Aloca memória para a matriz.|  
|[COleSafeArray::AllocDescriptor](#allocdescriptor)|Aloca memória para o descritor de matriz segura.|  
|[COleSafeArray::Attach](#attach)|Fornece controle de existente **VARIANT** de matriz para o `COleSafeArray` objeto.|  
|[COleSafeArray::Clear](#clear)|Libera todos os dados subjacentes **VARIANT**.|  
|[COleSafeArray::Copy](#copy)|Cria uma cópia de uma matriz existente.|  
|[COleSafeArray::Create](#create)|Cria uma matriz segura.|  
|[COleSafeArray::CreateOneDim](#createonedim)|Cria um unidimensional `COleSafeArray` objeto.|  
|[COleSafeArray::Destroy](#destroy)|Destrói a uma matriz existente.|  
|[COleSafeArray::DestroyData](#destroydata)|Destrói os dados em uma matriz segura.|  
|[COleSafeArray::DestroyDescriptor](#destroydescriptor)|Destrói um descritor de uma matriz segura.|  
|[COleSafeArray::Detach](#detach)|Desanexa o **VARIANT** matriz a `COleSafeArray` (de modo que os dados não serão liberados) do objeto.|  
|[COleSafeArray::GetByteArray](#getbytearray)|Copia o conteúdo da matriz segura em um [CByteArray](../../mfc/reference/cbytearray-class.md).|  
|[COleSafeArray::GetDim](#getdim)|Retorna o número de dimensões da matriz.|  
|[COleSafeArray::GetElement](#getelement)|Recupera um único elemento da matriz segura.|  
|[COleSafeArray::GetElemSize](#getelemsize)|Retorna o tamanho, em bytes, de um elemento em uma matriz segura.|  
|[COleSafeArray::GetLBound](#getlbound)|Retorna o limite inferior de qualquer dimensão de uma matriz segura.|  
|[COleSafeArray::GetOneDimSize](#getonedimsize)|Retorna o número de elementos a unidimensional `COleSafeArray` objeto.|  
|[COleSafeArray::GetUBound](#getubound)|Retorna o limite superior de qualquer dimensão de uma matriz segura.|  
|[COleSafeArray::Lock](#lock)|Incrementa a contagem de bloqueio de uma matriz e coloca um ponteiro para os dados de matriz no descritor de matriz.|  
|[COleSafeArray::PtrOfIndex](#ptrofindex)|Retorna um ponteiro para o elemento indexado.|  
|[COleSafeArray::PutElement](#putelement)|Atribui um único elemento na matriz.|  
|[COleSafeArray::Redim](#redim)|Altera o limite menos significativo (direito) de uma matriz segura.|  
|[COleSafeArray::ResizeOneDim](#resizeonedim)|Altera o número de elementos em um unidimensional `COleSafeArray` objeto.|  
|[COleSafeArray::UnaccessData](#unaccessdata)|Decrementa o bloqueio de contagem de uma matriz e invalida o ponteiro recuperado pelo `AccessData`.|  
|[COleSafeArray::Unlock](#unlock)|Decrementa o bloqueio de contagem de uma matriz para que possa ser liberada ou redimensionado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleSafeArray::operator LPCVARIANT](#operator_lpcvariant)|Acessa subjacente **VARIANT** estrutura do `COleSafeArray` objeto.|  
|[COleSafeArray::operator LPVARIANT](#operator_lpvariant)|Acessa subjacente **VARIANT** estrutura do `COleSafeArray` objeto.|  
|[COleSafeArray::operator =](#operator_eq)|Copia os valores em uma `COleSafeArray` objeto ( **SAFEARRAY**, **VARIANT**, `COleVariant`, ou `COleSafeArray` matriz).|  
|[COleSafeArray::operator = =](#operator_eq_eq)|Compara duas matrizes variantes ( **SAFEARRAY**, **VARIANTE**, `COleVariant`, ou `COleSafeArray` matrizes).|  
|[COleSafeArray::operator&lt;&lt;](#operator_lt_lt)|Gera o conteúdo de um `COleSafeArray` objeto ao contexto de despejo.|  
  
## <a name="remarks"></a>Comentários  
 `COleSafeArray`deriva a OLE **VARIANT** estrutura. O OLE **SAFEARRAY** funções de membro estão disponíveis por meio de `COleSafeArray`, bem como um conjunto de funções de membro projetado especificamente para matrizes unidimensionais de bytes.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `tagVARIANT`  
  
 `COleSafeArray`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="a-nameaccessdataa--colesafearrayaccessdata"></a><a name="accessdata"></a>COleSafeArray::AccessData  
 Recupera um ponteiro para os dados de matriz.  
  
```  
void AccessData(void** ppvData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppvData`  
 Um ponteiro para um ponteiro para os dados de matriz.  
  
### <a name="remarks"></a>Comentários  
 Em erro, a função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer&#26;](../../mfc/codesnippet/cpp/colesafearray-class_1.cpp)]  
  
##  <a name="a-nameallocdataa--colesafearrayallocdata"></a><a name="allocdata"></a>COleSafeArray::AllocData  
 Aloca memória para uma matriz segura.  
  
```  
void AllocData();
```  
  
### <a name="remarks"></a>Comentários  
 Em erro, a função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).  
  
##  <a name="a-nameallocdescriptora--colesafearrayallocdescriptor"></a><a name="allocdescriptor"></a>COleSafeArray::AllocDescriptor  
 Aloca memória para o descritor de uma matriz segura.  
  
```  
void AllocDescriptor(DWORD dwDims);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDims`  
 Número de dimensões da matriz segura.  
  
### <a name="remarks"></a>Comentários  
 Em erro, a função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).  
  
##  <a name="a-nameattacha--colesafearrayattach"></a><a name="attach"></a>COleSafeArray::Attach  
 Fornece controle dos dados em um **VARIANT** de matriz para o `COleSafeArray` objeto.  
  
```  
void Attach(VARIANT& varSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *varSrc*  
 A **VARIANT** objeto. O *varSrc* parâmetro deve ter o [VARTYPE](http://msdn.microsoft.com/en-us/317b911b-1805-402d-a9cb-159546bc88b4)**VT_ARRAY**.  
  
### <a name="remarks"></a>Comentários  
 A fonte **VARIANT**do tipo está definido como `VT_EMPTY`. Essa função limpa os dados de matriz atual, se houver.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [COleSafeArray::AccessData](#accessdata).  
  
##  <a name="a-namecleara--colesafearrayclear"></a><a name="clear"></a>COleSafeArray::Clear  
 Limpa a matriz segura.  
  
```  
void Clear();
```  
  
### <a name="remarks"></a>Comentários  
 A função limpa uma matriz segura definindo o `VARTYPE` do objeto `VT_EMPTY`. O conteúdo atual é liberado e a matriz é liberada.  
  
##  <a name="a-namecolesafearraya--colesafearraycolesafearray"></a><a name="colesafearray"></a>COleSafeArray::COleSafeArray  
 Constrói um objeto `COleSafeArray`.  
  
```  
COleSafeArray();

 
COleSafeArray(
    const SAFEARRAY& saSrc,
    VARTYPE vtSrc);

 
COleSafeArray(
    LPCSAFEARRAY pSrc,
    VARTYPE vtSrc);  
  
COleSafeArray(const COleSafeArray& saSrc);  
COleSafeArray(const VARIANT& varSrc);  
  COleSafeArray(LPCVARIANT pSrc);  
COleSafeArray(const COleVariant& varSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `saSrc`  
 Existente `COleSafeArray` objeto ou **SAFEARRAY** sejam copiados para o novo `COleSafeArray` objeto.  
  
 `vtSrc`  
 O **VARTYPE** do novo `COleSafeArray` objeto.  
  
 `psaSrc`  
 Um ponteiro para um **SAFEARRAY** sejam copiados para o novo `COleSafeArray` objeto.  
  
 *varSrc*  
 Existente **VARIANT** ou `COleVariant` o objeto a ser copiado para o novo `COleSafeArray` objeto.  
  
 `pSrc`  
 Um ponteiro para um **VARIANT** o objeto a ser copiado para o novo `COleSafeArray` objeto.  
  
### <a name="remarks"></a>Comentários  
 Todos esses construtores criar novos `COleSafeArray` objetos. Se não houver nenhum parâmetro, vazio `COleSafeArray` objeto é criado ( `VT_EMPTY`). Se o `COleSafeArray` é copiada de outra matriz cuja [VARTYPE](http://msdn.microsoft.com/en-us/317b911b-1805-402d-a9cb-159546bc88b4) é conhecido implicitamente (um `COleSafeArray`, `COleVariant`, ou **VARIANT**), o **VARTYPE** da fonte de matriz é mantida e não precisa ser especificado. Se o `COleSafeArray` é copiada de outra matriz cuja **VARTYPE** não é conhecido ( **SAFEARRAY**), o **VARTYPE** deve ser especificado no `vtSrc` parâmetro.  
  
 Em erro, a função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).  
  
##  <a name="a-namecopya--colesafearraycopy"></a><a name="copy"></a>COleSafeArray::Copy  
 Cria uma cópia de uma matriz de segurança existente.  
  
```  
void Copy(LPSAFEARRAY* ppsa);
```  
  
### <a name="parameters"></a>Parâmetros  
 *ppsa*  
 Ponteiro para um local no qual retornar o novo descritor de matriz.  
  
### <a name="remarks"></a>Comentários  
 Em erro, a função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).  
  
##  <a name="a-namecreatea--colesafearraycreate"></a><a name="create"></a>COleSafeArray::Create  
 Aloca e inicializa os dados da matriz.  
  
```  
void Create(
    VARTYPE vtSrc,  
    DWORD dwDims,  
    DWORD* rgElements);

 
void Create(
    VARTYPE vtSrc,  
    DWORD dwDims,  
    SAFEARRAYBOUND* rgsabounds);
```  
  
### <a name="parameters"></a>Parâmetros  
 `vtSrc`  
 O tipo base da matriz (ou seja, o **VARTYPE** de cada elemento da matriz). O **VARTYPE** é restrito a um subconjunto dos tipos variantes. Nem o **VT_ARRAY** nem **VT_BYREF** sinalizador pode ser definido. `VT_EMPTY`e **VT_NULL** não são tipos base válidos para a matriz. Todos os outros tipos são válidos.  
  
 `dwDims`  
 Número de dimensões da matriz. Isso pode ser alterado depois que a matriz é criada com [Redim](#redim).  
  
 *rgElements*  
 Ponteiro para uma matriz do número de elementos para cada dimensão da matriz.  
  
 *rgsabounds*  
 Ponteiro para um vetor de limites (uma para cada dimensão) para alocar para a matriz.  
  
### <a name="remarks"></a>Comentários  
 Esta função removerá os dados de matriz atual, se necessário. Em erro, a função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer&#27;](../../mfc/codesnippet/cpp/colesafearray-class_2.cpp)]  
  
##  <a name="a-namecreateonedima--colesafearraycreateonedim"></a><a name="createonedim"></a>COleSafeArray::CreateOneDim  
 Cria um novo unidimensional `COleSafeArray` objeto.  
  
```  
void CreateOneDim(
    VARTYPE vtSrc,  
    DWORD dwElements,  
    const void* pvSrcData = NULL,  
    long nLBound = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `vtSrc`  
 O tipo base da matriz (ou seja, o **VARTYPE** de cada elemento da matriz).  
  
 `dwElements`  
 Número de elementos na matriz. Isso pode ser alterado depois que a matriz é criada com [ResizeOneDim](#resizeonedim).  
  
 `pvSrcData`  
 Ponteiro para os dados a serem copiados na matriz.  
  
 *nLBound*  
 O limite inferior da matriz.  
  
### <a name="remarks"></a>Comentários  
 A função aloca e inicializa os dados para a matriz, copiando os dados especificados, se o ponteiro `pvSrcData` não é **nulo**.  
  
 Em erro, a função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer&#28;](../../mfc/codesnippet/cpp/colesafearray-class_3.cpp)]  
  
##  <a name="a-namedestroya--colesafearraydestroy"></a><a name="destroy"></a>COleSafeArray::Destroy  
 Destrói um descritor de matriz existente e todos os dados na matriz.  
  
```  
void Destroy();
```  
  
### <a name="remarks"></a>Comentários  
 Se os objetos são armazenados na matriz, cada objeto é liberado. Em erro, a função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).  
  
##  <a name="a-namedestroydataa--colesafearraydestroydata"></a><a name="destroydata"></a>COleSafeArray::DestroyData  
 Destrói todos os dados em uma matriz segura.  
  
```  
void DestroyData();
```  
  
### <a name="remarks"></a>Comentários  
 Se os objetos são armazenados na matriz, cada objeto é liberado. Em erro, a função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).  
  
##  <a name="a-namedestroydescriptora--colesafearraydestroydescriptor"></a><a name="destroydescriptor"></a>COleSafeArray::DestroyDescriptor  
 Destrói um descritor de uma matriz segura.  
  
```  
void DestroyDescriptor();
```  
  
### <a name="remarks"></a>Comentários  
 Em erro, a função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).  
  
##  <a name="a-namedetacha--colesafearraydetach"></a><a name="detach"></a>COleSafeArray::Detach  
 Desanexa o **VARIANT** dados a partir de `COleSafeArray` objeto.  
  
```  
VARIANT Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Subjacente **VARIANT** o valor de `COleSafeArray` objeto.  
  
### <a name="remarks"></a>Comentários  
 A função separa os dados em uma matriz segura, definindo o [VARTYPE](http://msdn.microsoft.com/en-us/317b911b-1805-402d-a9cb-159546bc88b4) do objeto `VT_EMPTY`. É responsabilidade do chamador liberar a matriz chamando a função do Windows [VariantClear](http://msdn.microsoft.com/en-us/28741d81-8404-4f85-95d3-5c209ec13835).  
  
 Em erro, a função gera uma [COleException](../../mfc/reference/coleexception-class.md).  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [COleSafeArray::PutElement](#putelement).  
  
##  <a name="a-namegetbytearraya--colesafearraygetbytearray"></a><a name="getbytearray"></a>COleSafeArray::GetByteArray  
 Copia o conteúdo da matriz segura em um `CByteArray`.  
  
```  
void GetByteArray(CByteArray& bytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bytes`  
 Uma referência a um [CByteArray](../../mfc/reference/cbytearray-class.md) objeto.  
  
##  <a name="a-namegetdima--colesafearraygetdim"></a><a name="getdim"></a>COleSafeArray::GetDim  
 Retorna o número de dimensões no `COleSafeArray` objeto.  
  
```  
DWORD GetDim();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de dimensões da matriz segura.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer&#27;](../../mfc/codesnippet/cpp/colesafearray-class_2.cpp)]  
  
##  <a name="a-namegetelementa--colesafearraygetelement"></a><a name="getelement"></a>COleSafeArray::GetElement  
 Recupera um único elemento da matriz segura.  
  
```  
void GetElement(
    long* rgIndices,  
    void* pvData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rgIndices`  
 Ponteiro para uma matriz de índices para cada dimensão da matriz.  
  
 `pvData`  
 Ponteiro para o local para colocar o elemento da matriz.  
  
### <a name="remarks"></a>Comentários  
 Essa função automaticamente chama as funções do windows `SafeArrayLock` e `SafeArrayUnlock` antes e depois de recuperar o elemento. Se o elemento de dados for uma cadeia de caracteres, objeto ou variante, a função copia o elemento da maneira correta. O parâmetro `pvData` deve apontar para uma grande buffer suficiente para conter o elemento.  
  
 Em erro, a função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[29 NVC_MFCOleContainer](../../mfc/codesnippet/cpp/colesafearray-class_4.cpp)]  
  
##  <a name="a-namegetelemsizea--colesafearraygetelemsize"></a><a name="getelemsize"></a>COleSafeArray::GetElemSize  
 Recupera o tamanho de um elemento em uma `COleSafeArray` objeto.  
  
```  
DWORD GetElemSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho, em bytes, dos elementos de uma matriz segura.  
  
##  <a name="a-namegetlbounda--colesafearraygetlbound"></a><a name="getlbound"></a>COleSafeArray::GetLBound  
 Retorna o limite inferior de qualquer dimensão de uma `COleSafeArray` objeto.  
  
```  
void GetLBound(
    DWORD dwDim,  
    long* pLBound);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDim`  
 A dimensão da matriz para a qual obter o limite inferior.  
  
 *pLBound*  
 Ponteiro para o local para retornar o limite inferior.  
  
### <a name="remarks"></a>Comentários  
 Em erro, a função gera uma [COleException](../../mfc/reference/coleexception-class.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[30 NVC_MFCOleContainer](../../mfc/codesnippet/cpp/colesafearray-class_5.cpp)]  
  
##  <a name="a-namegetonedimsizea--colesafearraygetonedimsize"></a><a name="getonedimsize"></a>COleSafeArray::GetOneDimSize  
 Retorna o número de elementos a unidimensional `COleSafeArray` objeto.  
  
```  
DWORD GetOneDimSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos na matriz unidimensional seguro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [COleSafeArray::CreateOneDim](#createonedim).  
  
##  <a name="a-namegetubounda--colesafearraygetubound"></a><a name="getubound"></a>COleSafeArray::GetUBound  
 Retorna o limite superior de qualquer dimensão de uma matriz segura.  
  
```  
void GetUBound(
    DWORD dwDim,  
    long* pUBound);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDim`  
 A dimensão da matriz para a qual obter o limite superior.  
  
 *pUBound*  
 Ponteiro para o local para retornar o limite superior.  
  
### <a name="remarks"></a>Comentários  
 Em erro, a função gera uma [COleException](../../mfc/reference/coleexception-class.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer&#31;](../../mfc/codesnippet/cpp/colesafearray-class_6.cpp)]  
  
##  <a name="a-namelocka--colesafearraylock"></a><a name="lock"></a>COleSafeArray::Lock  
 Incrementa a contagem de bloqueio de uma matriz e um ponteiro para os dados de matriz no descritor de matriz local.  
  
```  
void Lock();
```  
  
### <a name="remarks"></a>Comentários  
 No erro, ele gerará uma [COleException](../../mfc/reference/coleexception-class.md).  
  
 O ponteiro no descritor de matriz é válido até `Unlock` é chamado. Chamadas para `Lock` podem ser aninhados; um número igual de chamadas para `Unlock` são necessários.  
  
 Uma matriz não pode ser excluída enquanto ele estiver bloqueado.  
  
##  <a name="a-nameoperatorlpcvarianta--colesafearrayoperator-lpcvariant"></a><a name="operator_lpcvariant"></a>COleSafeArray::operator LPCVARIANT  
 Chame esse operador de conversão para acessar subjacente **VARIANT** estrutura para isso `COleSafeArray` objeto.  
  
```  
operator LPCVARIANT() const;  
```  
  
##  <a name="a-nameoperatorlpvarianta--colesafearrayoperator-lpvariant"></a><a name="operator_lpvariant"></a>COleSafeArray::operator LPVARIANT  
 Chame esse operador de conversão para acessar subjacente **VARIANT** estrutura para isso `COleSafeArray` objeto.  
  
```  
operator LPVARIANT();
```   
  
### <a name="remarks"></a>Comentários  
 Observe que alterar o valor o **VARIANT** estrutura acessada pelo ponteiro retornado por essa função alterará o valor desse `COleSafeArray` objeto.  
  
##  <a name="a-nameoperatoreqa--colesafearrayoperator-"></a><a name="operator_eq"></a>COleSafeArray::operator =  
 Esses operadores de atribuição sobrecarregados copie o valor de origem para este `COleSafeArray` objeto.  
  
```  
COleSafeArray& operator=(const COleSafeArray& saSrc);  
COleSafeArray& operator=(const VARIANT& varSrc);  
  COleSafeArray& operator=(LPCVARIANT pSrc);  
COleSafeArray& operator=(const COleVariant& varSrc);
```  
  
### <a name="remarks"></a>Comentários  
 Segue uma breve descrição de cada operador:  
  
- **operador = (** *saSrc* **)** copia existente `COleSafeArray` objeto para esse objeto.  
  
- **operador = (** *varSrc***)** copia existente **VARIANT** ou `COleVariant` matriz para esse objeto.  
  
- **operador = (** `pSrc` **)** cópias de **VARIANT** objeto array acessado por `pSrc` para esse objeto.  
  
##  <a name="a-nameoperatoreqeqa--colesafearrayoperator-"></a><a name="operator_eq_eq"></a>COleSafeArray::operator = =  
 Este operador compara duas matrizes ( **SAFEARRAY**, **VARIANT**, `COleVariant`, ou `COleSafeArray` matrizes) e retorna zero se eles forem iguais; caso contrário, 0.  
  
```  
BOOL operator==(const SAFEARRAY& saSrc) const;  BOOL operator==(LPCSAFEARRAY pSrc) const;  
   
BOOL operator==(const COleSafeArray& saSrc) const;  BOOL operator==(const VARIANT& varSrc) const;  
   
BOOL operator==(LPCVARIANT pSrc) const;  BOOL operator==(const COleVariant& varSrc) const;  ```  
  
### Remarks  
 Two arrays are equal if they have an equal number of dimensions, equal size in each dimension, and equal element values.  
  
##  <a name="operator_lt_lt"></a>  COleSafeArray::operator &lt;&lt;  
 The `COleSafeArray` insertion (<<) operator supports diagnostic dumping and storing of a `COleSafeArray` object to an archive.  
  
```  
Operador de AFXAPI de < / CDumpContext<( CDumpContext& dc, cdumpcontext&=""></( CDumpContext& dc,>  
    COleSafeArray < / saSrc);
```  
  
##  <a name="ptrofindex"></a>  COleSafeArray::PtrOfIndex  
 Returns a pointer to the element specified by the index values.  
  
```  
void PtrOfIndex (longo* rgIndices, void** ppvData);
```  
  
### Parameters  
 `rgIndices`  
 An array of index values that identify an element of the array. All indexes for the element must be specified.  
  
 `ppvData`  
 On return, pointer to the element identified by the values in `rgIndices`.  
  
##  <a name="putelement"></a>  COleSafeArray::PutElement  
 Assigns a single element into the array.  
  
```  
void PutElement (longo* rgIndices, void* pvData);
```  
  
### Parameters  
 `rgIndices`  
 Pointer to an array of indexes for each dimension of the array.  
  
 `pvData`  
 Pointer to the data to assign to the array. **VT_DISPATCH**, **VT_UNKNOWN**, and `VT_BSTR` variant types are pointers and do not require another level of indirection.  
  
### Remarks  
 This function automatically calls the Windows functions [SafeArrayLock](https://msdn.microsoft.com/library/windows/desktop/ms221492.aspx) and [SafeArrayUnlock](https://msdn.microsoft.com/library/windows/desktop/ms221246.aspx) before and after assigning the element. If the data element is a string, object, or variant, the function copies it correctly, and if the existing element is a string, object, or variant, it is cleared correctly.  
  
 Note that you can have multiple locks on an array, so you can put elements into an array while the array is locked by other operations.  
  
 On error, the function throws a [CMemoryException](../../mfc/reference/cmemoryexception-class.md) or [COleException](../../mfc/reference/coleexception-class.md).  
  
### Example  
 [!code-cpp[NVC_MFCOleContainer#32](../../mfc/codesnippet/cpp/colesafearray-class_7.cpp)]  
  
##  <a name="redim"></a>  COleSafeArray::Redim  
 Changes the least significant (rightmost) bound of a safe array.  
  
```  
void Redim (SAFEARRAYBOUND * psaboundNew);
```  
  
### Parameters  
 *psaboundNew*  
 Pointer to a new safe array bound structure containing the new array bound. Only the least significant dimension of an array may be changed.  
  
### Remarks  
 On error, the function throws a [COleException](../../mfc/reference/coleexception-class.md).  
  
##  <a name="resizeonedim"></a>  COleSafeArray::ResizeOneDim  
 Changes the number of elements in a one-dimensional `COleSafeArray` object.  
  
```  
void ResizeOneDim (DWORD dwElements);
```  
  
### Parameters  
 `dwElements`  
 Number of elements in the one-dimensional safe array.  
  
### Remarks  
 On error, the function throws a [COleException](../../mfc/reference/coleexception-class.md).  
  
### Example  
  See the example for [COleSafeArray::CreateOneDim](#createonedim).  
  
##  <a name="unaccessdata"></a>  COleSafeArray::UnaccessData  
 Decrements the lock count of an array and invalidates the pointer retrieved by `AccessData`.  
  
```  
void UnaccessData();
```  
  
### Remarks  
 On error, the function throws a [COleException](../../mfc/reference/coleexception-class.md).  
  
### Example  
  See the example for [COleSafeArray::AccessData](#accessdata).  
  
##  <a name="unlock"></a>  COleSafeArray::Unlock  
 Decrements the lock count of an array so it can be freed or resized.  
  
```  
void Unlock();
```  
  
### Remarks  
 This function is called after access to the data in an array is finished. On error, it throws a [COleException](../../mfc/reference/coleexception-class.md).  
  
## See Also  
 [Hierarchy Chart](../../mfc/hierarchy-chart.md)   
 [COleVariant Class](../../mfc/reference/colevariant-class.md)   
 [CRecordset Class](../../mfc/reference/crecordset-class.md)   
 [CDatabase Class](../../mfc/reference/cdatabase-class.md)

