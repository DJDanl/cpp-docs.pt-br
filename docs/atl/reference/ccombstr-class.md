---
title: CComBSTR-classe | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComBSTR
- ATLBASE/ATL::CComBSTR
- ATLBASE/ATL::CComBSTR::CComBSTR
- ATLBASE/ATL::CComBSTR::Append
- ATLBASE/ATL::CComBSTR::AppendBSTR
- ATLBASE/ATL::CComBSTR::AppendBytes
- ATLBASE/ATL::CComBSTR::ArrayToBSTR
- ATLBASE/ATL::CComBSTR::AssignBSTR
- ATLBASE/ATL::CComBSTR::Attach
- ATLBASE/ATL::CComBSTR::BSTRToArray
- ATLBASE/ATL::CComBSTR::ByteLength
- ATLBASE/ATL::CComBSTR::Copy
- ATLBASE/ATL::CComBSTR::CopyTo
- ATLBASE/ATL::CComBSTR::Detach
- ATLBASE/ATL::CComBSTR::Empty
- ATLBASE/ATL::CComBSTR::Length
- ATLBASE/ATL::CComBSTR::LoadString
- ATLBASE/ATL::CComBSTR::ReadFromStream
- ATLBASE/ATL::CComBSTR::ToLower
- ATLBASE/ATL::CComBSTR::ToUpper
- ATLBASE/ATL::CComBSTR::WriteToStream
- ATLBASE/ATL::CComBSTR::m_str
dev_langs:
- C++
helpviewer_keywords:
- BSTRs, wrapper
- CComBSTR class
- CComBSTR
ms.assetid: 8fea1879-a05e-47a5-a803-8dec60eaa534
caps.latest.revision: 21
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
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: 4c7ab8630a4793f0363567fa00cecb8a3bc19e3b
ms.lasthandoff: 03/31/2017

---
# <a name="ccombstr-class"></a>CComBSTR-classe
Essa classe é um wrapper para `BSTR`s.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComBSTR
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComBSTR::CComBSTR](#ccombstr)|O construtor.|  
|[CComBSTR:: ~ CComBSTR](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComBSTR::Append](#append)|Acrescenta uma cadeia de caracteres para `m_str`.|  
|[CComBSTR::AppendBSTR](#appendbstr)|Acrescenta um `BSTR` para `m_str`.|  
|[CComBSTR::AppendBytes](#appendbytes)|Acrescenta um número especificado de bytes a serem `m_str`.|  
|[CComBSTR::ArrayToBSTR](#arraytobstr)|Cria um `BSTR` partir do primeiro caractere de cada elemento na safearray e anexa-o para o `CComBSTR` objeto.|  
|[CComBSTR::AssignBSTR](#assignbstr)|Atribui um `BSTR` para `m_str`.|  
|[CComBSTR::Attach](#attach)|Anexa uma `BSTR` para o `CComBSTR` objeto.|  
|[CComBSTR::BSTRToArray](#bstrtoarray)|Cria um safearray unidimensional com base em zero, onde cada elemento da matriz é um caractere do `CComBSTR` objeto.|  
|[CComBSTR::ByteLength](#bytelength)|Retorna o comprimento de `m_str` em bytes.|  
|[CComBSTR::Copy](#copy)|Retorna uma cópia do `m_str`.|  
|[CComBSTR::CopyTo](#copyto)|Retorna uma cópia do `m_str` por meio de um **[out]** parâmetro|  
|[CComBSTR::Detach](#detach)|Desanexa `m_str` do `CComBSTR` objeto.|  
|[CComBSTR::Empty](#empty)|Libera `m_str`.|  
|[CComBSTR::Length](#length)|Retorna o comprimento de `m_str`.|  
|[CComBSTR::LoadString](#loadstring)|Carrega um recurso de cadeia de caracteres.|  
|[CComBSTR::ReadFromStream](#readfromstream)|Carrega um `BSTR` objeto a partir de um fluxo.|  
|[CComBSTR::ToLower](#tolower)|Converte a cadeia de caracteres em minúsculas.|  
|[CComBSTR::ToUpper](#toupper)|Converte a cadeia de caracteres em maiusculas.|  
|[CComBSTR::WriteToStream](#writetostream)|Salva `m_str` em um fluxo.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComBSTR::operator BSTR](#operator_bstr)|Conversões de um `CComBSTR` o objeto para um `BSTR`.|  
|[CComBSTR::operator!](#operator_not)|Retorna `true` ou `false`, dependendo se `m_str`é `NULL`.|  
|[CComBSTR::operator! =](#operator_neq)|Compara uma `CComBSTR` com uma cadeia de caracteres.|  
|[CComBSTR::operator &](#operator_amp)|Retorna o endereço de `m_str`.|  
|[+ CComBSTR::operator =](#operator_add_eq)|Anexa uma `CComBSTR` ao objeto.|  
|[CComBSTR::operator](#operator_lt)|Compara uma `CComBSTR` com uma cadeia de caracteres.|  
|[CComBSTR::operator =](#operator_eq)|Atribui um valor para `m_str`.|  
|[CComBSTR::operator = =](#operator_eq_eq)|Compara uma `CComBSTR` com uma cadeia de caracteres.|  
|[CComBSTR::operator >](#operator_gt)|Compara uma `CComBSTR` com uma cadeia de caracteres.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComBSTR::m_str](#m_str)|Contém o `BSTR` associados a `CComBSTR` objeto.|  
  
## <a name="remarks"></a>Comentários  
 O `CComBSTR` classe é um wrapper para `BSTR`s, que são cadeias de caracteres de prefixo de comprimento. O comprimento é armazenado como um número inteiro no local de memória que precede os dados na cadeia de caracteres.  
  
 Um [BSTR](http://msdn.microsoft.com/en-us/1b2d7d2c-47af-4389-a6b6-b01b7e915228) é terminada em nulo após o último contados caractere, mas também pode conter caracteres nulos inseridos na cadeia de caracteres. O comprimento da cadeia de caracteres é determinado pela contagem de caracteres, não o primeiro caractere nulo.  
  
> [!NOTE]
>  O `CComBSTR` classe fornece um número de membros (construtores, operadores de atribuição e operadores de comparação) que usam cadeias de caracteres ANSI ou Unicode como argumentos. As versões de ANSI dessas funções são menos eficientes do que seus equivalentes Unicode, como cadeias de caracteres Unicode temporárias geralmente são criadas internamente. Para eficiência, use as versões do Unicode sempre que possível.  
  
> [!NOTE]
>  Devido ao comportamento de pesquisa aprimorada implementado no Visual Studio .NET, como código `bstr = L"String2" + bstr;`, que pode ter compiladas em versões anteriores, em vez disso, devem ser implementadas como `bstr = CStringW(L"String2") + bstr`.  
  
 Para obter uma lista de cuidados ao usar `CComBSTR`, consulte [programação com o CComBSTR](../../atl/programming-with-ccombstr-atl.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="append"></a>CComBSTR::Append  
 Acrescenta o `lpsz` ou `BSTR` membro `bstrSrc` para [m_str](#m_str).  
  
```
HRESULT Append(const CComBSTR& bstrSrc) throw();
HRESULT Append(wchar_t ch) throw();
HRESULT Append(char ch) throw();
HRESULT Append(LPCOLESTR lpsz) throw();
HRESULT Append(LPCSTR lpsz) throw();
HRESULT Append(LPCOLESTR lpsz, int nLen) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bstrSrc`  
 [in] Um `CComBSTR` objeto a ser acrescentado.  
  
 *CH*  
 [in] Um caractere para anexar.  
  
 `lpsz`  
 [in] Uma cadeia de caracteres terminada em zero para anexar. Você pode passar uma cadeia de caracteres Unicode por meio de **LPCOLESTR** sobrecarga ou uma cadeia de caracteres ANSI via o `LPCSTR` versão.  
  
 `nLen`  
 [in] O número de caracteres de `lpsz` acrescentar.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`em caso de sucesso ou qualquer padrão `HRESULT` valor de erro.  
  
### <a name="remarks"></a>Comentários  
 Uma cadeia de caracteres ANSI será convertida para Unicode antes que está sendo anexado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities #32](../../atl/codesnippet/cpp/ccombstr-class_1.cpp)]  
  
##  <a name="appendbstr"></a>CComBSTR::AppendBSTR  
 Acrescenta especificado `BSTR` para [m_str](#m_str).  
  
```
HRESULT AppendBSTR(BSTR p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 [in] Um `BSTR` para anexar.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`em caso de sucesso ou qualquer padrão `HRESULT` valor de erro.  
  
### <a name="remarks"></a>Comentários  
 Não passe uma cadeia de caracteres largos comum para esse método. O compilador não pode capturar o erro e ocorrerão erros de tempo de execução.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[33 NVC_ATL_Utilities](../../atl/codesnippet/cpp/ccombstr-class_2.cpp)]  
  
##  <a name="appendbytes"></a>CComBSTR::AppendBytes  
 Acrescenta o número especificado de bytes a serem [m_str](#m_str) sem conversão.  
  
```
HRESULT AppendBytes(const char* lpsz, int nLen) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpsz`  
 [in] Um ponteiro para uma matriz de bytes a ser acrescentada.  
  
 `p`  
 [in] O número de bytes a ser acrescentada.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`em caso de sucesso ou qualquer padrão `HRESULT` valor de erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities #34](../../atl/codesnippet/cpp/ccombstr-class_3.cpp)]  
  
##  <a name="arraytobstr"></a>CComBSTR::ArrayToBSTR  
 Libera qualquer cadeia de caracteres existente mantida no `CComBSTR` do objeto e, em seguida, cria um `BSTR` partir do primeiro caractere de cada elemento na safearray e anexa-o para o `CComBSTR` objeto.  
  
```
HRESULT ArrayToBSTR(const SAFEARRAY* pSrc) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSrc`  
 [in] A safearray que contém os elementos usados para criar a cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`em caso de sucesso ou qualquer padrão `HRESULT` valor de erro.  
  
##  <a name="assignbstr"></a>CComBSTR::AssignBSTR  
 Atribui um `BSTR` para [m_str](#m_str).  
  
```
HRESULT AssignBSTR(const BSTR bstrSrc) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bstrSrc`  
 [in] Um `BSTR` para atribuir a atual `CComBSTR` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`em caso de sucesso ou qualquer padrão `HRESULT` valor de erro.  
  
##  <a name="attach"></a>CComBSTR::Attach  
 Anexa uma `BSTR` para o `CComBSTR` objeto definindo o [m_str](#m_str) membro *src*.  
  
```
void Attach(BSTR src) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *src*  
 [in] O `BSTR` para anexar ao objeto.  
  
### <a name="remarks"></a>Comentários  
 Não passe uma cadeia de caracteres largos comum para esse método. O compilador não pode capturar o erro e ocorrerão erros de tempo de execução.  
  
> [!NOTE]
>  Esse método declarará se `m_str` é não - **nulo**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities n º 35](../../atl/codesnippet/cpp/ccombstr-class_4.cpp)]  
  
##  <a name="bstrtoarray"></a>CComBSTR::BSTRToArray  
 Cria um safearray unidimensional com base em zero, onde cada elemento da matriz é um caractere do `CComBSTR` objeto.  
  
```
HRESULT BSTRToArray(LPSAFEARRAY* ppArray) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppArray`  
 [out] O ponteiro para safearray usado para armazenar os resultados da função.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`em caso de sucesso ou qualquer padrão `HRESULT` valor de erro.  
  
##  <a name="bytelength"></a>CComBSTR::ByteLength  
 Retorna o número de bytes em `m_str`, exceto o caractere null de terminação.  
  
```
unsigned int ByteLength() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento do [m_str](#m_str) membro em bytes.  
  
### <a name="remarks"></a>Comentários  
 Retorna 0 se `m_str` é **nulo**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[36 NVC_ATL_Utilities](../../atl/codesnippet/cpp/ccombstr-class_5.cpp)]  
  
##  <a name="ccombstr"></a>CComBSTR::CComBSTR  
 O construtor. Os conjuntos de construtor padrão de [m_str](#m_str) membro **nulo**.  
  
```
CComBSTR() throw();
CComBSTR(const CComBSTR& src);  
CComBSTR(REFGUID  guid);  
CComBSTR(int nSize);  
CComBSTR(int nSize, LPCOLESTR sz);  
CComBSTR(int nSize, LPCSTR sz);  
CComBSTR(LPCOLESTR pSrc);  
CComBSTR(LPCSTR pSrc);  
CComBSTR(CComBSTR&& src) throw(); // (Visual Studio 2017)
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSize`  
 [in] O número de caracteres a serem copiados do `sz` ou o tamanho inicial em caracteres para o `CComBSTR`.  
  
 `sz`  
 [in] Uma cadeia de caracteres a serem copiados. Especifica a versão Unicode uma **LPCOLESTR**; a versão ANSI Especifica um `LPCSTR`.  
  
 `pSrc`  
 [in] Uma cadeia de caracteres a serem copiados. Especifica a versão Unicode uma **LPCOLESTR**; a versão ANSI Especifica um `LPCSTR`.  
  
 *src*  
 [in] Um `CComBSTR` objeto.  
  
 `guid`  
 [in] Uma referência a um **GUID** estrutura.  
  
### <a name="remarks"></a>Comentários  
 Os conjuntos de construtor de cópia `m_str` uma cópia da `BSTR` membro *src*. O **REFGUID** construtor converte o **GUID** para uma cadeia de caracteres usando **StringFromGUID2** e armazena o resultado.  
  
 Conjunto de construtores `m_str` uma cópia de cadeia de caracteres especificada. Se você passar um valor `nSize`, então somente `nSize` caracteres serão copiados, seguido por um caractere null de terminação.  
  
 `CComBSTR`dá suporte a move semântica. Você pode usar o construtor de movimento (o construtor que usa uma referência rvalue ( `&&`) para criar um novo objeto que usa os mesmos dados subjacentes, conforme você passar como um argumento, sem a sobrecarga de cópia do objeto do objeto antigo.  
  
 O destruidor libera a cadeia de caracteres apontada por `m_str`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities º 37](../../atl/codesnippet/cpp/ccombstr-class_6.cpp)]  
  
##  <a name="dtor"></a>CComBSTR:: ~ CComBSTR  
 O destruidor.  
  
```
~CComBSTR();
```  
  
### <a name="remarks"></a>Comentários  
 O destruidor libera a cadeia de caracteres apontada por `m_str`.  
  
##  <a name="copy"></a>CComBSTR::Copy  
 Aloca e retorna uma cópia do `m_str`.  
  
```
BSTR Copy() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cópia do [m_str](#m_str) membro. If `m_str` is **NULL**, returns **NULL**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities 38](../../atl/codesnippet/cpp/ccombstr-class_7.cpp)]  
  
##  <a name="copyto"></a>CComBSTR::CopyTo  
 Aloca e retorna uma cópia do [m_str](#m_str) por meio do parâmetro.  
  
```
HRESULT CopyTo(BSTR* pbstr) throw();

HRESULT CopyTo(VARIANT* pvarDest) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbstr*  
 [out] O endereço de um `BSTR` no qual retornar a cadeia de caracteres alocada por esse método.  
  
 `pvarDest`  
 [out] O endereço de um **VARIANT** no qual retornar a cadeia de caracteres alocada por esse método.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor que indica o êxito ou falha da cópia.  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar esse método, o **VARIANT** apontada pelo `pvarDest` será do tipo `VT_BSTR`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities #39](../../atl/codesnippet/cpp/ccombstr-class_8.cpp)]  
  
##  <a name="detach"></a>CComBSTR::Detach  
 Desanexa [m_str](#m_str) do `CComBSTR` objeto e conjuntos de `m_str` para **nulo**.  
  
```
BSTR Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `BSTR` associados a `CComBSTR` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[40 NVC_ATL_Utilities](../../atl/codesnippet/cpp/ccombstr-class_9.cpp)]  
  
##  <a name="empty"></a>CComBSTR::Empty  
 Libera o [m_str](#m_str) membro.  
  
```
void Empty() throw();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities 41](../../atl/codesnippet/cpp/ccombstr-class_10.cpp)]  
  
##  <a name="length"></a>CComBSTR::Length  
 Retorna o número de caracteres em `m_str`, exceto o caractere null de terminação.  
  
```
unsigned int Length() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento do [m_str](#m_str) membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities #42](../../atl/codesnippet/cpp/ccombstr-class_11.cpp)]  
  
##  <a name="loadstring"></a>CComBSTR::LoadString  
 Carrega um recurso de cadeia de caracteres especificado por `nID` e armazena-o neste objeto.  
  
```
bool LoadString(HINSTANCE hInst, UINT nID) throw();
bool LoadString(UINT nID) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 Consulte [LoadString](http://msdn.microsoft.com/library/windows/desktop/ms647486) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se a cadeia de caracteres com êxito carregado; caso contrário, retorna **false**.  
  
### <a name="remarks"></a>Comentários  
 A primeira função carrega o recurso do módulo identificado por você por meio de `hInst` parâmetro. A segunda função carrega o recurso do módulo de recursos associado a [CComModule](../../atl/reference/ccommodule-class.md)-derivados do objeto usado neste projeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities º 43](../../atl/codesnippet/cpp/ccombstr-class_12.cpp)]  
  
##  <a name="m_str"></a>CComBSTR::m_str  
 Contém o `BSTR` associados a `CComBSTR` objeto.  
  
```
BSTR m_str;
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[49 NVC_ATL_Utilities](../../atl/codesnippet/cpp/ccombstr-class_13.cpp)]  
  
##  <a name="operator_bstr"></a>CComBSTR::operator BSTR  
 Conversões de um `CComBSTR` o objeto para um `BSTR`.  
  
```  
operator BSTR() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Permite que você passe `CComBSTR` objetos para funções que têm **[in] BSTR** parâmetros.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CComBSTR::m_str](#m_str).  
  
##  <a name="operator_not"></a>CComBSTR::operator!  
 Verifica se `BSTR` cadeia de caracteres é NULL.  
  
```
bool operator!() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o [m_str](#m_str) membro é **nulo**; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 Este operador só verifica um valor nulo, não para uma cadeia de caracteres vazia.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities n º 35](../../atl/codesnippet/cpp/ccombstr-class_4.cpp)]  
  
##  <a name="operator_neq"></a>CComBSTR::operator! =  
 Retorna a lógica oposta [operador = =](#operator_eq_eq).  
  
```
bool operator!= (const CComBSTR& bstrSrc) const throw();
bool operator!= (LPCOLESTR pszSrc) const;
bool operator!= (LPCSTR pszSrc) const;
bool operator!= (int nNull) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bstrSrc`  
 [in] Um `CComBSTR` objeto.  
  
 `pszSrc`  
 [in] Uma cadeia de caracteres terminada em zero.  
  
 `nNull`  
 [in] Deve ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o item que estão sendo comparado não é igual a `CComBSTR` objeto; caso contrário, retornará **false**.  
  
### <a name="remarks"></a>Comentários  
 `CComBSTR`s são comparados textualmente no contexto de localidade do padrão do usuário. O operador de comparação final apenas compara a cadeia de caracteres independente **nulo**.  
  
##  <a name="operator_amp"></a>CComBSTR::operator&amp;  
 Retorna o endereço do `BSTR` armazenados no [m_str](#m_str) membro.  
  
```
BSTR* operator&() throw();
```  
  
### <a name="remarks"></a>Comentários  
 `CComBstr operator &`tem uma declaração especial associado para ajudar a identificar vazamentos de memória. O programa declarará quando o `m_str` membro é inicializado. Esta declaração foi criada para identificar situações em que um programador usa o `& operator` para atribuir um novo valor para `m_str` membro sem liberar a primeira alocação de `m_str`. Se `m_str` é igual a NULL, o programa assumirá que m_str não foi distribuída ainda. Nesse caso, o programa não será assert.  
  
 Esta declaração não é habilitada por padrão. Definir `ATL_CCOMBSTR_ADDRESS_OF_ASSERT` para habilitar essa asserção.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[46 NVC_ATL_Utilities](../../atl/codesnippet/cpp/ccombstr-class_14.cpp)]  
  
 [!code-cpp[NVC_ATL_Utilities #47](../../atl/codesnippet/cpp/ccombstr-class_15.cpp)]  
  
##  <a name="operator_add_eq"></a>+ CComBSTR::operator =  
 Acrescenta uma cadeia de caracteres para o `CComBSTR` objeto.  
  
```
CComBSTR& operator+= (const CComBSTR& bstrSrc);  
CComBSTR& operator+= (const LPCOLESTR pszSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bstrSrc`  
 [in] Um `CComBSTR` objeto a ser acrescentado.  
  
 `pszSrc`  
 [in] Uma cadeia terminada em zero para anexar.  
  
### <a name="remarks"></a>Comentários  
 `CComBSTR`s são comparados textualmente no contexto de localidade do padrão do usuário. O **LPCOLESTR** comparação é feita usando `memcmp` nos dados brutos em cada cadeia de caracteres. O `LPCSTR` comparação é executada da mesma forma quando um temporário Unicode copiará `pszSrc` foi criado. O operador de comparação final apenas compara a cadeia de caracteres independente **nulo**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[48 NVC_ATL_Utilities](../../atl/codesnippet/cpp/ccombstr-class_16.cpp)]  
  
##  <a name="operator_lt"></a>CComBSTR::operator&lt;  
 Compara uma `CComBSTR` com uma cadeia de caracteres.  
  
```
bool operator<(const CComBSTR& bstrSrc) const throw();
bool operator<(LPCOLESTR pszSrc) const throw();
bool operator<(LPCSTR pszSrc) const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o item que estão sendo comparado for menor do que o `CComBSTR` objeto; caso contrário, retornará **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação é executada usando a localidade do usuário padrão.  
  
##  <a name="operator_eq"></a>CComBSTR::operator =  
 Conjuntos de [m_str](#m_str) membro a uma cópia de `pSrc` ou uma cópia do `BSTR` membro do *src*. O operador de atribuição de movimentação move `src` sem copiá-lo.   
  
```
CComBSTR& operator= (const CComBSTR& src);  
CComBSTR& operator= (LPCOLESTR pSrc);  
CComBSTR& operator= (LPCSTR pSrc);
CComBSTR& operator= (CComBSTR&& src) throw(); // (Visual Studio 2017)
```  
  
### <a name="remarks"></a>Comentários  
 O `pSrc` parâmetro especifica um **LPCOLESTR** para versões de Unicode ou `LPCSTR` para versões ANSI.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CComBSTR::Copy](#copy).  
  
##  <a name="operator_eq_eq"></a>CComBSTR::operator = =  
 Compara uma `CComBSTR` com uma cadeia de caracteres. `CComBSTR`s são comparados textualmente no contexto de localidade do padrão do usuário.  
  
```
bool operator== (const CComBSTR& bstrSrc) const throw();
bool operator== (LPCOLESTR pszSrc) const;
bool operator== (LPCSTR pszSrc) const;
bool operator== (int nNull) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bstrSrc`  
 [in] Um `CComBSTR` objeto.  
  
 `pszSrc`  
 [in] Uma cadeia de caracteres terminada em zero.  
  
 `nNull`  
 [in] Deve ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o item que está sendo comparado é igual de `CComBSTR` objeto; caso contrário, retornará **false**.  
  
### <a name="remarks"></a>Comentários  
 O operador de comparação final apenas compara a cadeia de caracteres independente **nulo**.  
  
##  <a name="operator_gt"></a>CComBSTR::operator&gt;  
 Compara uma `CComBSTR` com uma cadeia de caracteres.  
  
```
bool operator>(const CComBSTR& bstrSrc) const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o item que estão sendo comparado for maior do que o `CComBSTR` objeto; caso contrário, retornará **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação é executada usando a localidade do usuário padrão.  
  
##  <a name="readfromstream"></a>CComBSTR::ReadFromStream  
 Conjuntos de [m_str](#m_str) membro para o `BSTR` contidos no fluxo especificado.  
  
```
HRESULT ReadFromStream(IStream* pStream) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStream`  
 [in] Um ponteiro para o [IStream](http://msdn.microsoft.com/library/windows/desktop/aa380034) interface no fluxo que contém os dados.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 **ReadToStream** requer o conteúdo do fluxo da posição atual para ser compatível com o formato de dados gravado por uma chamada para [WriteToStream](#writetostream).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities º 44](../../atl/codesnippet/cpp/ccombstr-class_17.cpp)]  
  
##  <a name="tolower"></a>CComBSTR::ToLower  
 Converte a cadeia de caracteres contida em minúsculas.  
  
```
HRESULT ToLower() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Consulte **CharLowerBuff** para obter mais informações sobre como a conversão é executada.  
  
##  <a name="toupper"></a>CComBSTR::ToUpper  
 Converte a cadeia de caracteres contida em maiusculas.  
  
```
HRESULT ToUpper() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Consulte **CharUpperBuff** para obter mais informações sobre como a conversão é executada.  
  
##  <a name="writetostream"></a>CComBSTR::WriteToStream  
 Salva o [m_str](#m_str) membro em um fluxo.  
  
```
HRESULT WriteToStream(IStream* pStream) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStream`  
 [in] Um ponteiro para o [IStream](http://msdn.microsoft.com/library/windows/desktop/aa380034) interface em um fluxo.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Você pode recriar um BSTR do conteúdo de fluxo usando o [ReadFromStream](#readfromstream) função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[45 NVC_ATL_Utilities](../../atl/codesnippet/cpp/ccombstr-class_18.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [ATL e MFC Macros de conversão de cadeia de caracteres](string-conversion-macros.md)

