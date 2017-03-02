---
title: Classe CStrBufT | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CStrBufT<TCharType>
- ATL.CStrBufT
- CStrBufT
- ATL::CStrBufT
- ATL.CStrBufT<TCharType>
dev_langs:
- C++
helpviewer_keywords:
- strings [C++], custom memory management
- CStrBufT class
- shared classes, CStrBufT
ms.assetid: 6b50fa8f-87e8-4ed4-a229-157ce128710f
caps.latest.revision: 17
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
ms.openlocfilehash: 2eb551d2db029de88aa9c1b456c44609b7fc0922
ms.lasthandoff: 02/25/2017

---
# <a name="cstrbuft-class"></a>Classe CStrBufT
Essa classe fornece a limpeza de recursos automáticos de `GetBuffer` e `ReleaseBuffer` chama em uma `CStringT` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename TCharType>
class CStrBufT
```  
  
#### <a name="parameters"></a>Parâmetros  
 *TCharType*  
 O tipo de caractere da `CStrBufT` classe. Pode ser uma das seguintes opções:  
  
- `char`(para cadeias de caracteres ANSI)  
  
- `wchar_t`(para cadeias de caracteres Unicode)  
  
- **TCHAR** (para cadeias de caracteres ANSI e Unicode)  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`PCXSTR`|Um ponteiro para uma cadeia de caracteres constante.|  
|`PXSTR`|Um ponteiro para uma cadeia de caracteres.|  
|`StringType`|O tipo de cadeia de caracteres cujo buffer deve ser manipulado pelo especializações deste modelo de classe.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStrBufT::CStrBufT](#cstrbuft)|O construtor para o objeto de buffer de cadeia de caracteres.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStrBufT::SetLength](#setlength)|Define o comprimento do buffer de caracteres do objeto de cadeia de caracteres associado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStrBufT::operator PCXSTR](#operator_pcxstr)|Recupera um **const** ponteiro para o buffer de caracteres do objeto de cadeia de caracteres associado.|  
|[CStrBufT::operator PXSTR](#operator_pxstr)|Recupera um ponteiro para o buffer de caracteres do objeto de cadeia de caracteres associado.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStrBufT::AUTO_LENGTH](#auto_length)|Determine automaticamente o novo tamanho da cadeia de caracteres nesta versão.|  
|[CStrBufT::SET_LENGTH](#set_length)|Definir o tamanho do objeto de cadeia de caracteres em tempo de GetBuffer|  
  
## <a name="remarks"></a>Comentários  
 Essa classe é usada como uma classe de wrapper para a substituição das chamadas [GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) e [ReleaseBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#releasebuffer), ou [GetBufferSetLength](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffersetlength) e `ReleaseBuffer`.  
  
 Desenvolvido como uma classe auxiliar, `CStrBufT` fornece uma maneira conveniente para trabalhar com o buffer de caracteres de um objeto de cadeia de caracteres sem se preocupar como um desenvolvedor ou quando chamar `ReleaseBuffer`. Isso é possível porque o objeto wrapper sai do escopo naturalmente no caso de uma exceção ou vários caminhos de código existente; fazendo com que seu destruidor liberar o recurso de cadeia de caracteres.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpstr.h  
  
##  <a name="a-nameautolengtha--cstrbuftautolength"></a><a name="auto_length"></a>CStrBufT::AUTO_LENGTH  
 Determine automaticamente o novo tamanho da cadeia de caracteres nesta versão.  
  
```
static const DWORD AUTO_LENGTH = 0x01;
```  
  
### <a name="remarks"></a>Comentários  
 Determine automaticamente o novo tamanho da cadeia de caracteres nesta versão. A cadeia de caracteres deve ser terminada em nulo.  
  
##  <a name="a-namecstrbufta--cstrbuftcstrbuft"></a><a name="cstrbuft"></a>CStrBufT::CStrBufT  
 Constrói um objeto de buffer.  
  
```
CStrBufT(StringType& str, int nMinLength, DWORD dwFlags = AUTO_LENGTH) throw(...);
explicit CStrBufT(StringType& str) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 O objeto de cadeia de caracteres associado com o buffer. Normalmente, o desenvolvedor usará o typedefs predefinido de **CStrBuf** ( **TCHAR** variante), **CStrBufA** ( `char` variant) e **CStrBufW** ( `wchar_t` variant).  
  
 *nMinLength*  
 O comprimento mínimo de buffer de caracteres.  
  
 `dwFlags`  
 Determina se o comprimento da cadeia de caracteres é determinado automaticamente. Pode ser uma das seguintes opções:  
  
- **AUTO_LENGTH** comprimento de cadeia de caracteres é automaticamente determinado quando [CSimpleStringT::Release](../../atl-mfc-shared/reference/csimplestringt-class.md#releasebuffer) é chamado. A cadeia de caracteres deve ser terminada em nulo. Valor padrão.  
  
- **SET_LENGTH** comprimento de cadeia de caracteres é definido quando [CSimpleStringT::GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) é chamado.  
  
### <a name="remarks"></a>Comentários  
 Cria um buffer de cadeia de caracteres para o objeto de cadeia de caracteres associado. Durante a construção, [CSimpleStringT::GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) ou [CSimpleStringT::GetBufferSetLength](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffersetlength) é chamado.  
  
 Observe que o construtor de cópia é `private`.  
  
##  <a name="a-nameoperatorpcxstra--cstrbuftoperator-pcxstr"></a><a name="operator_pcxstr"></a>CStrBufT::operator PCXSTR  
 Acessa diretamente os caracteres armazenados no objeto de cadeia de caracteres associados como uma cadeia de caracteres de estilo C.  
  
```  
operator PCXSTR() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro de caractere para dados da cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para retornar um ponteiro para o buffer de caracteres de um objeto de cadeia de caracteres. O conteúdo do objeto de cadeia de caracteres não pode ser alterado com esse ponteiro.  
  
##  <a name="a-nameoperatorpxstra--cstrbuftoperator-pxstr"></a><a name="operator_pxstr"></a>CStrBufT::operator PXSTR  
 Acessa diretamente os caracteres armazenados no objeto de cadeia de caracteres associados como uma cadeia de caracteres de estilo C.  
  
```
operator PXSTR() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro de caractere para dados da cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para retornar um ponteiro para o buffer de caracteres de um objeto de cadeia de caracteres. O desenvolvedor pode alterar o conteúdo do objeto de cadeia de caracteres com esse ponteiro.  
  
##  <a name="a-namepcxstra--cstrbuftpcxstr"></a><a name="pcxstr"></a>CStrBufT::PCXSTR  
 Um ponteiro para uma cadeia de caracteres constante.  
  
```
typedef CSimpleStringT<TCharType>::PCXSTR PCXSTR;
```  
  
##  <a name="a-namepxstra--cstrbuftpxstr"></a><a name="pxstr"></a>CStrBufT::PXSTR  
 Um ponteiro para uma cadeia de caracteres.  
  
```
typedef CSimpleStringT<TCharType>::PXSTR PXSTR;
```  
  
##  <a name="a-namesetlengtha--cstrbuftsetlength"></a><a name="set_length"></a>CStrBufT::SET_LENGTH  
 Definir o tamanho do objeto de cadeia de caracteres no `GetBuffer` tempo.  
  
```
static const DWORD SET_LENGTH = 0x02;
```  
  
### <a name="remarks"></a>Comentários  
 Defina o tamanho do objeto de cadeia de caracteres em tempo de GetBuffer.  
  
 Determina se [CSimpleStringT::GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) e [CSimpleStringT::GetBufferSetLength](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffersetlength) são chamados quando o objeto de buffer de cadeia de caracteres é construído.  
  
##  <a name="a-namesetlengtha--cstrbuftsetlength"></a><a name="setlength"></a>CStrBufT::SetLength  
 Define o comprimento do buffer de caracteres.  
  
```
void SetLength(int nLength);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLength`  
 O novo tamanho do buffer do objeto de cadeia de caracteres.  
  
> [!NOTE]
>  Deve ser menor ou igual ao comprimento de buffer mínimo especificado no construtor do `CStrBufT`.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para definir o comprimento da cadeia de caracteres representada pelo objeto de buffer.  
  
##  <a name="a-namestringtypea--cstrbuftstringtype"></a><a name="stringtype"></a>CStrBufT::StringType  
 O tipo de cadeia de caracteres cujo buffer deve ser manipulado pelo especializações deste modelo de classe.  
  
```
typedef CSimpleStringT<TCharType> StringType;
```  
  
### <a name="remarks"></a>Comentários  
 **TCharType** é o tipo de caractere usado para especializar o modelo de classe.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes compartilhadas do ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)



