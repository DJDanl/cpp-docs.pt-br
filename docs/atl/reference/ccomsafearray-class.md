---
title: Classe CComSafeArray | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComSafeArray
- ATLSAFE/ATL::CComSafeArray
- ATLSAFE/ATL::CComSafeArray::CComSafeArray
- ATLSAFE/ATL::CComSafeArray::Add
- ATLSAFE/ATL::CComSafeArray::Attach
- ATLSAFE/ATL::CComSafeArray::CopyFrom
- ATLSAFE/ATL::CComSafeArray::CopyTo
- ATLSAFE/ATL::CComSafeArray::Create
- ATLSAFE/ATL::CComSafeArray::Destroy
- ATLSAFE/ATL::CComSafeArray::Detach
- ATLSAFE/ATL::CComSafeArray::GetAt
- ATLSAFE/ATL::CComSafeArray::GetCount
- ATLSAFE/ATL::CComSafeArray::GetDimensions
- ATLSAFE/ATL::CComSafeArray::GetLowerBound
- ATLSAFE/ATL::CComSafeArray::GetSafeArrayPtr
- ATLSAFE/ATL::CComSafeArray::GetType
- ATLSAFE/ATL::CComSafeArray::GetUpperBound
- ATLSAFE/ATL::CComSafeArray::IsSizable
- ATLSAFE/ATL::CComSafeArray::MultiDimGetAt
- ATLSAFE/ATL::CComSafeArray::MultiDimSetAt
- ATLSAFE/ATL::CComSafeArray::Resize
- ATLSAFE/ATL::CComSafeArray::SetAt
- ATLSAFE/ATL::CComSafeArray::m_psa
dev_langs:
- C++
helpviewer_keywords:
- CComSafeArray class
ms.assetid: ee349aef-33db-4c85-bd08-5d86a3c9d53a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 28be6dffc2f991ad08c83c508af2c401d5eecc37
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38959365"
---
# <a name="ccomsafearray-class"></a>Classe CComSafeArray
Essa classe é um wrapper para o `SAFEARRAY` estrutura.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename T, VARTYPE _vartype = _ATL_AutomationType<T>::type>
class CComSafeArray
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 O tipo de dados a serem armazenados na matriz.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComSafeArray::CComSafeArray](#ccomsafearray)|O construtor.|  
|[CComSafeArray:: ~ CComSafeArray](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Ccomsafearray:: Add](#add)|Adiciona um ou mais elementos, ou um `SAFEARRAY` estrutura, como um `CComSafeArray`.|  
|[CComSafeArray::Attach](#attach)|Anexa uma `SAFEARRAY` estrutura para um `CComSafeArray` objeto.|  
|[Ccomsafearray:: CopyFrom](#copyfrom)|Copia o conteúdo de um `SAFEARRAY` estrutura no `CComSafeArray` objeto.|  
|[CComSafeArray::CopyTo](#copyto)|Cria uma cópia do objeto `CComSafeArray`.|  
|[CComSafeArray::Create](#create)|Cria um objeto `CComSafeArray`.|  
|[CComSafeArray::Destroy](#destroy)|Destrói um objeto `CComSafeArray`.|  
|[Ccomsafearray:: Detach](#detach)|Desanexa um `SAFEARRAY` de um `CComSafeArray` objeto.|  
|[Ccomsafearray:: Getat](#getat)|Recupera um único elemento de uma matriz unidimensional.|  
|[CComSafeArray::GetCount](#getcount)|Retorna o número de elementos na matriz.|  
|[CComSafeArray::GetDimensions](#getdimensions)|Retorna o número de dimensões na matriz.|  
|[CComSafeArray::GetLowerBound](#getlowerbound)|Retorna o limite inferior de uma determinada dimensão da matriz.|  
|[CComSafeArray::GetSafeArrayPtr](#getsafearrayptr)|Retorna o endereço do `m_psa` membro de dados.|  
|[CComSafeArray::GetType](#gettype)|Retorna o tipo de dados armazenados na matriz.|  
|[CComSafeArray::GetUpperBound](#getupperbound)|Retorna o limite superior de qualquer dimensão da matriz.|  
|[CComSafeArray::IsSizable](#issizable)|Testa se um `CComSafeArray` objeto pode ser redimensionado.|  
|[CComSafeArray::MultiDimGetAt](#multidimgetat)|Recupera um único elemento de uma matriz multidimensional.|  
|[CComSafeArray::MultiDimSetAt](#multidimsetat)|Define o valor de um elemento em uma matriz multidimensional.|  
|[CComSafeArray::Resize](#resize)|Redimensiona um `CComSafeArray` objeto.|  
|[Setat](#setat)|Define o valor de um elemento em uma matriz unidimensional.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComSafeArray::operator LPSAFEARRAY](#operator_lpsafearray)|Converte um valor para um `SAFEARRAY` ponteiro.|  
|[CComSafeArray::operator\[\]](ccomsafearray-class.md#operator_at)|Recupera um elemento da matriz.|  
|[CComSafeArray::operator =](#operator_eq)|Operador de atribuição.|  

  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComSafeArray::m_psa](#m_psa)|Este membro de dados contém o endereço do `SAFEARRAY` estrutura.|  
  
## <a name="remarks"></a>Comentários  
 `CComSafeArray` Fornece um wrapper para o [tipo de dados do SAFEARRAY](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagsafearray) classe, tornando muito simples para criar e gerenciar matrizes unidimensional e multidimensionais de quase qualquer um dos tipos com suporte da VARIANTE.  
  
 `CComSafeArray` simplifica a passar matrizes entre processos e Além disso, fornece segurança adicional, verificando os valores de índice de matriz no canto superior e os limites inferiores.  
  
 O limite inferior de um `CComSafeArray` pode iniciar com qualquer valor definido pelo usuário; no entanto, matrizes que são acessados por meio de C++ devem usar um limite inferior de 0. Outras linguagens como Visual Basic podem usar outros valores de delimitadores (por exemplo, -10 a 10).  
  
 Use [CComSafeArray::Create](#create) para criar um `CComSafeArray` objeto, e [CComSafeArray::Destroy](#destroy) para excluí-lo.  
  
 Um `CComSafeArray` pode conter o seguinte subconjunto dos tipos de dados VARIANTE:  
  
|VARTYPE|Descrição|  
|-------------|-----------------|  
|VT_I1|char|  
|VT_I2|short|  
|VT_I4|int|  
|VT_I4|long|  
|VT_I8|longlong|  
|VT_UI1|byte|  
|VT_UI2|ushort|  
|VT_UI4|uint|  
|VT_UI4|ulong|  
|VT_UI8|ULONGLONG|  
|VT_R4|float|  
|VT_R8|double|  
|VT_DECIMAL|ponteiro decimal|  
|VT_VARIANT|ponteiro Variant|  
|VT_CY|tipo de dados Currency|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsafe. h  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#75](../../atl/codesnippet/cpp/ccomsafearray-class_1.cpp)]  
  
##  <a name="add"></a>  Ccomsafearray:: Add  
 Adiciona um ou mais elementos, ou um `SAFEARRAY` estrutura, como um `CComSafeArray`.  
  
```
HRESULT Add(const SAFEARRAY* psaSrc);
HRESULT Add(ULONG ulCount, const T* pT, BOOL bCopy = TRUE);
HRESULT Add(const T& t, BOOL bCopy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *psaSrc*  
 Um ponteiro para um `SAFEARRAY` objeto.  
  
 *ulCount*  
 O número de objetos a serem adicionados à matriz.  
  
 *pT*  
 Um ponteiro para um ou mais objetos a ser adicionado à matriz.  
  
 *t*  
 Uma referência ao objeto a ser adicionado à matriz.  
  
 *bCopy*  
 Indica se uma cópia dos dados deve ser criada. O valor padrão é TRUE.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no êxito ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Os novos objetos são acrescentados ao final da existente `SAFEARRAY` objeto. Adicionar um objeto a um multidimensional `SAFEARRAY` não há suporte para o objeto. Ao adicionar uma matriz existente de objetos, ambas as matrizes devem conter elementos do mesmo tipo.  
  
 O *bCopy* sinalizador é levado em conta quando elementos do tipo BSTR ou VARIANTE são adicionados a uma matriz. O valor padrão de TRUE assegura que é feita uma nova cópia dos dados quando o elemento é adicionado à matriz.  
  
##  <a name="attach"></a>  CComSafeArray::Attach  
 Anexa uma `SAFEARRAY` estrutura para um `CComSafeArray` objeto.  
  
```
HRESULT Attach(const SAFEARRAY* psaSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *psaSrc*  
 Um ponteiro para o `SAFEARRAY` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no êxito ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Anexa uma `SAFEARRAY` estrutura para um `CComSafeArray` objeto, tornando existente `CComSafeArray` métodos disponíveis.  
  
##  <a name="ccomsafearray"></a>  CComSafeArray::CComSafeArray  
 O construtor.  
  
```
CComSafeArray();
CComSafeArray(const SAFEARRAYBOUND& bound);
CComSafeArray(ULONG  ulCount, LONG lLBound = 0);
CComSafeArray(const SAFEARRAYBOUND* pBound, UINT uDims = 1);
CComSafeArray(const CComSafeArray& saSrc);
CComSafeArray(const SAFEARRAY& saSrc);
CComSafeArray(const SAFEARRAY* psaSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *associado*  
 Uma estrutura `SAFEARRAYBOUND`.  
  
 *ulCount*  
 O número de elementos na matriz.  
  
 *lLBound*  
 O valor de limite inferior; ou seja, o índice do primeiro elemento na matriz.  
  
 *pBound*  
 Um ponteiro para um `SAFEARRAYBOUND` estrutura.  
  
 *uDims*  
 A contagem de dimensões na matriz.  
  
 *saSrc*  
 Uma referência a um `SAFEARRAY` estrutura ou `CComSafeArray` objeto. Em ambos os casos o construtor usa essa referência para fazer uma cópia da matriz, portanto, a matriz não é referenciada após a construção.  
  
 *psaSrc*  
 Um ponteiro para um `SAFEARRAY` estrutura. O construtor usa esse endereço para fazer uma cópia da matriz, portanto, a matriz não é referenciada após a construção.  
  
### <a name="remarks"></a>Comentários  
 Cria um objeto `CComSafeArray`.  
  
##  <a name="dtor"></a>  CComSafeArray:: ~ CComSafeArray  
 O destruidor.  
  
```
~CComSafeArray() throw()
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="copyfrom"></a>  Ccomsafearray:: CopyFrom  
 Copia o conteúdo de um `SAFEARRAY` estrutura no `CComSafeArray` objeto.  
  
```
HRESULT CopyFrom(LPSAFEARRAY* ppArray);
```  
  
### <a name="parameters"></a>Parâmetros  
 *ppArray*  
 Ponteiro para o `SAFEARRAY` para copiar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no êxito ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método copia o conteúdo de um `SAFEARRAY` com o atual `CComSafeArray` objeto. O conteúdo existente da matriz é substituído.  
  
##  <a name="copyto"></a>  CComSafeArray::CopyTo  
 Cria uma cópia do objeto `CComSafeArray`.  
  
```
HRESULT CopyTo(LPSAFEARRAY* ppArray);
```  
  
### <a name="parameters"></a>Parâmetros  
 *ppArray*  
 Um ponteiro para um local no qual criar o novo `SAFEARRAY`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no êxito ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método copia o conteúdo de um `CComSafeArray` do objeto em um `SAFEARRAY` estrutura.  
  
##  <a name="create"></a>  CComSafeArray::Create  
 Cria um `CComSafeArray`.  
  
```
HRESULT Create(const SAFEARRAYBOUND* pBound, UINT uDims = 1);
HRESULT Create(ULONG ulCount = 0, LONG lLBound = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pBound*  
 Um ponteiro para um `SAFEARRAYBOUND` objeto.  
  
 *uDims*  
 O número de dimensões na matriz.  
  
 *ulCount*  
 O número de elementos na matriz.  
  
 *lLBound*  
 O valor de limite inferior; ou seja, o índice do primeiro elemento na matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no êxito ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Um `CComSafeArray` objeto pode ser criado de uma já existente `SAFEARRAYBOUND` estrutura e o número de dimensões ou especificando o número de elementos na matriz e o limite inferior. Se a matriz deve ser acessado a partir do Visual C++, o limite inferior deve ser 0. Outras linguagens podem permitir que outros valores para o limite inferior (por exemplo, Visual Basic é compatível com matrizes com elementos com um intervalo como -10 a 10).  
  
##  <a name="destroy"></a>  CComSafeArray::Destroy  
 Destrói um objeto `CComSafeArray`.  
  
```
HRESULT Destroy();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no êxito ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Destrói um existente `CComSafeArray` objeto e todos os dados que ele contém.  
  
##  <a name="detach"></a>  Ccomsafearray:: Detach  
 Desanexa um `SAFEARRAY` de um `CComSafeArray` objeto.  
  
```
LPSAFEARRAY Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para um `SAFEARRAY` objeto.  
  
### <a name="remarks"></a>Comentários  
 Esse método desanexa o `SAFEARRAY` objeto o `CComSafeArray` objeto.  
  
##  <a name="getat"></a>  Ccomsafearray:: Getat  
 Recupera um único elemento de uma matriz unidimensional.  
  
```
T& GetAt(LONG lIndex) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 *lIndex*  
 O número de índice do valor na matriz a retornar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência ao elemento de matriz necessários.  
  
##  <a name="getcount"></a>  CComSafeArray::GetCount  
 Retorna o número de elementos na matriz.  
  
```
ULONG GetCount(UINT uDim = 0) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 *uDim*  
 A dimensão de matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de elementos na matriz.  
  
### <a name="remarks"></a>Comentários  
 Quando usado com uma matriz multidimensional, esse método retornará o número de elementos em uma dimensão específica apenas.  
  
##  <a name="getdimensions"></a>  CComSafeArray::GetDimensions  
 Retorna o número de dimensões na matriz.  
  
```
UINT GetDimensions() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de dimensões na matriz.  
  
##  <a name="getlowerbound"></a>  CComSafeArray::GetLowerBound  
 Retorna o limite inferior de uma determinada dimensão da matriz.  
  
```
LONG GetLowerBound(UINT uDim = 0) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 *uDim*  
 A dimensão de matriz para o qual obter o limite inferior. Se omitido, o padrão é 0.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o limite inferior.  
  
### <a name="remarks"></a>Comentários  
 Se o limite inferior é 0, isso indica uma matriz do tipo C cujo primeiro elemento é o número do elemento 0. Em caso de erro, por exemplo, um argumento de dimensão inválida, este método chama `AtlThrow` com um HRESULT que descreve o erro.  
  
##  <a name="getsafearrayptr"></a>  CComSafeArray::GetSafeArrayPtr  
 Retorna o endereço do `m_psa` membro de dados.  
  
```
LPSAFEARRAY* GetSafeArrayPtr() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o [CComSafeArray::m_psa](#m_psa) membro de dados.  
  
##  <a name="gettype"></a>  CComSafeArray::GetType  
 Retorna o tipo de dados armazenados na matriz.  
  
```
VARTYPE GetType() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o tipo de dados armazenados na matriz, que pode ser qualquer um dos seguintes tipos:  
  
|VARTYPE|Descrição|  
|-------------|-----------------|  
|VT_I1|char|  
|VT_I2|short|  
|VT_I4|int|  
|VT_I4|long|  
|VT_I8|longlong|  
|VT_UI1|byte|  
|VT_UI2|ushort|  
|VT_UI4|uint|  
|VT_UI4|ulong|  
|VT_UI8|ULONGLONG|  
|VT_R4|float|  
|VT_R8|double|  
|VT_DECIMAL|ponteiro decimal|  
|VT_VARIANT|ponteiro Variant|  
|VT_CY|tipo de dados Currency|  
  
##  <a name="getupperbound"></a>  CComSafeArray::GetUpperBound  
 Retorna o limite superior de qualquer dimensão da matriz.  
  
```
LONG GetUpperBound(UINT uDim = 0) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 *uDim*  
 A dimensão de matriz para o qual obter o limite superior. Se omitido, o padrão é 0.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o limite superior. Esse valor é inclusivo, o índice máximo válido para essa dimensão.  
  
### <a name="remarks"></a>Comentários  
 Em caso de erro, por exemplo, um argumento de dimensão inválida, este método chama `AtlThrow` com um HRESULT que descreve o erro.  
  
##  <a name="issizable"></a>  CComSafeArray::IsSizable  
 Testa se um `CComSafeArray` objeto pode ser redimensionado.  
  
```
bool IsSizable() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o `CComSafeArray` pode ser redimensionado, FALSE se não for possível.  
  
##  <a name="m_psa"></a>  CComSafeArray::m_psa  
 Contém o endereço do `SAFEARRAY` estrutura acessada.  
  
```
LPSAFEARRAY m_psa;
```  
  
##  <a name="multidimgetat"></a>  CComSafeArray::MultiDimGetAt  
 Recupera um único elemento de uma matriz multidimensional.  
  
```
HRESULT MultiDimGetAt(const LONG* alIndex, T& t);
```  
  
### <a name="parameters"></a>Parâmetros  
 *alIndex*  
 Ponteiro para um vetor de índices para cada dimensão da matriz. A dimensão (o mais significativo) mais à esquerda é `alIndex[0]`.  
  
 *t*  
 Uma referência aos dados retornados.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no êxito ou um erro HRESULT em caso de falha.  
  
##  <a name="multidimsetat"></a>  CComSafeArray::MultiDimSetAt  
 Define o valor de um elemento em uma matriz multidimensional.  
  
```
HRESULT MultiDimSetAt(const LONG* alIndex, const T& t);
```  
  
### <a name="parameters"></a>Parâmetros  
 *alIndex*  
 Ponteiro para um vetor de índices para cada dimensão da matriz. A dimensão (menos significativa) mais à direita é `alIndex`[0].  
  
 *T*  
 Especifica o valor do novo elemento.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no êxito ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esta é uma versão multidimensional do [Setat](#setat).  
  
##  <a name="operator_at"></a>  CComSafeArray::operator \[\]  
 Recupera um elemento da matriz.  
  
```
T& operator[](long lindex) const;
T& operator[]int nindex) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 *lIndex, nIndex*  
 O número de índice do elemento necessário na matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o elemento de matriz apropriada.  
  
### <a name="remarks"></a>Comentários  
 Executa uma função semelhante aos [ccomsafearray:: Getat](#getat), no entanto, este operador funciona apenas com matrizes unidimensionais.  
  
##  <a name="operator_eq"></a>  CComSafeArray::operator =  
 Operador de atribuição.  
  
```
ATL::CComSafeArray<T>& operator=(const ATL::CComSafeArray& saSrc);
ATL::CComSafeArray<T>& operator=(const SAFEARRAY* psaSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *saSrc*  
 Uma referência a um objeto `CComSafeArray`.  
  
 *psaSrc*  
 Um ponteiro para um `SAFEARRAY` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o tipo de dados armazenados na matriz.  
  
##  <a name="operator_lpsafearray"></a>  CComSafeArray::operator LPSAFEARRAY  
 Converte um valor para um `SAFEARRAY` ponteiro.  
  
```
operator LPSAFEARRAY() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Converte um valor para um `SAFEARRAY` ponteiro.  
  
##  <a name="resize"></a>  CComSafeArray::Resize  
 Redimensiona um `CComSafeArray` objeto.  
  
```
HRESULT Resize(const SAFEARRAYBOUND* pBound);
HRESULT Resize(ULONG ulCount, LONG lLBound = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pBound*  
 Um ponteiro para um `SAFEARRAYBOUND` estrutura que contém informações sobre o número de elementos e o limite inferior de uma matriz.  
  
 *ulCount*  
 O número solicitado de objetos na matriz redimensionada.  
  
 *lLBound*  
 O limite inferior.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no êxito ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método só redimensiona a dimensão mais à direita. Ele não será redimensionado que retornam matrizes `IsResizable` como FALSE.  
  
##  <a name="setat"></a>  Setat  
 Define o valor de um elemento em uma matriz unidimensional.  
  
```
HRESULT SetAt(LONG lIndex, const T& t, BOOL bCopy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lIndex*  
 O número de índice do elemento de matriz a ser definido.  
  
 *t*  
 O novo valor do elemento especificado.  
  
 *bCopy*  
 Indica se uma cópia dos dados deve ser criada. O valor padrão é TRUE.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no êxito ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O *bCopy* sinalizador é levado em conta quando elementos do tipo BSTR ou VARIANTE são adicionados a uma matriz. O valor padrão de TRUE assegura que é feita uma nova cópia dos dados quando o elemento é adicionado à matriz.  
  
## <a name="see-also"></a>Consulte também  
 [Tipo de dados do SAFEARRAY](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagsafearray)   
 [CComSafeArray::Create](#create)   
 [CComSafeArray::Destroy](#destroy)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
