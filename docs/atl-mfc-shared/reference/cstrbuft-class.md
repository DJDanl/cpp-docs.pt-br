---
title: Classe CStrBufT
ms.date: 10/18/2018
f1_keywords:
- CStrBufT
- ATLSIMPSTR/ATL::CStrBufT
- ATLSIMPSTR/ATL::CStrBufT::CStrBufT
- ATLSIMPSTR/ATL::CStrBufT::SetLength
- ATLSIMPSTR/ATL::CStrBufT::AUTO_LENGTH
- ATLSIMPSTR/ATL::CStrBufT::SET_LENGTH
helpviewer_keywords:
- strings [C++], custom memory management
- CStrBufT class
- shared classes, CStrBufT
ms.assetid: 6b50fa8f-87e8-4ed4-a229-157ce128710f
ms.openlocfilehash: 81c3b429089eab3ba95c178e3fc7cf2bf55783a2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62223487"
---
# <a name="cstrbuft-class"></a>Classe CStrBufT

Essa classe fornece a limpeza de recursos automáticos `GetBuffer` e `ReleaseBuffer` chama em um existente `CStringT` objeto.

## <a name="syntax"></a>Sintaxe

```
template<typename TCharType>
class CStrBufT
```

#### <a name="parameters"></a>Parâmetros

*TCharType*<br/>
O tipo de caracteres a `CStrBufT` classe. Pode ser uma das seguintes opções:

- **char** (para cadeias de caracteres ANSI)

- **wchar_t** (para cadeias de caracteres Unicode)

- TCHAR (para cadeias de caracteres ANSI e Unicode)

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|PCXSTR|Um ponteiro para uma cadeia de caracteres constante.|
|PXSTR|Um ponteiro para uma cadeia de caracteres.|
|`StringType`|O tipo de cadeia de caracteres cujo buffer deve ser manipulado por especializações desse modelo de classe.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CStrBufT::CStrBufT](#cstrbuft)|O construtor para o objeto de buffer de cadeia de caracteres.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStrBufT::SetLength](#setlength)|Define o comprimento do buffer de caracteres do objeto de cadeia de caracteres associada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CStrBufT::operator PCXSTR](#operator_pcxstr)|Recupera uma **const** ponteiro para o buffer de caracteres do objeto de cadeia de caracteres associada.|
|[CStrBufT::operator PXSTR](#operator_pxstr)|Recupera um ponteiro para o buffer de caracteres do objeto de cadeia de caracteres associada.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[CStrBufT::AUTO_LENGTH](#auto_length)|Determine automaticamente o novo comprimento da cadeia de caracteres nesta versão.|
|[CStrBufT::SET_LENGTH](#set_length)|Definir o tamanho do objeto de cadeia de caracteres em tempo de GetBuffer|

## <a name="remarks"></a>Comentários

Essa classe é usada como uma classe wrapper para a substituição das chamadas [GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) e [ReleaseBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#releasebuffer), ou [GetBufferSetLength](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffersetlength) e `ReleaseBuffer`.

Projetado principalmente como uma classe do auxiliar `CStrBufT` fornece uma maneira conveniente para trabalhar com o buffer de caracteres de um objeto de cadeia de caracteres sem se preocupar sobre como um desenvolvedor ou quando chamar `ReleaseBuffer`. Isso é possível porque o objeto do wrapper sai do escopo naturalmente no caso de uma exceção ou vários caminhos de código existente; fazendo com que seu destruidor liberar o recurso de cadeia de caracteres.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpstr.h

##  <a name="auto_length"></a>  CStrBufT::AUTO_LENGTH

Determine automaticamente o novo comprimento da cadeia de caracteres nesta versão.

```
static const DWORD AUTO_LENGTH = 0x01;
```

### <a name="remarks"></a>Comentários

Determine automaticamente o novo comprimento da cadeia de caracteres nesta versão. A cadeia de caracteres deve ser terminada em nulo.

##  <a name="cstrbuft"></a>  CStrBufT::CStrBufT

Constrói um objeto de buffer.

```
CStrBufT(StringType& str, int nMinLength, DWORD dwFlags = AUTO_LENGTH) throw(...);
explicit CStrBufT(StringType& str) throw(...);
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
O objeto de cadeia de caracteres associado com o buffer. Normalmente, o desenvolvedor usará o typedefs predefinido da `CStrBuf` (variante TCHAR), `CStrBufA` (**char** variant) e `CStrBufW` (**wchar_t** variante).

*nMinLength*<br/>
O comprimento mínimo do buffer de caractere.

*dwFlags*<br/>
Determina se o comprimento da cadeia de caracteres é determinado automaticamente. Pode ser uma das seguintes opções:

- Comprimento de cadeia de caracteres AUTO_LENGTH é automaticamente determinado quando [CSimpleStringT::Release](../../atl-mfc-shared/reference/csimplestringt-class.md#releasebuffer) é chamado. A cadeia de caracteres deve ser terminada em nulo. Valor padrão.

- Comprimento da cadeia de caracteres SET_LENGTH é definido quando [CSimpleStringT::GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) é chamado.

### <a name="remarks"></a>Comentários

Cria um buffer de cadeia de caracteres para o objeto de cadeia de caracteres associada. Durante a construção, [CSimpleStringT::GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) ou [CSimpleStringT::GetBufferSetLength](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffersetlength) é chamado.

Observe que é o construtor de cópia **privada**.

##  <a name="operator_pcxstr"></a>  CStrBufT::operator PCXSTR

Acessa diretamente caracteres armazenados no objeto de cadeia de caracteres associado como uma cadeia de caracteres de estilo C.

```
operator PCXSTR() const throw();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro de caractere para dados da cadeia de caracteres.

### <a name="remarks"></a>Comentários

Chame essa função para retornar um ponteiro para o buffer de caracteres de um objeto de cadeia de caracteres. O conteúdo do objeto de cadeia de caracteres não pode ser alterado com esse ponteiro.

##  <a name="operator_pxstr"></a>  CStrBufT::operator PXSTR

Acessa diretamente caracteres armazenados no objeto de cadeia de caracteres associado como uma cadeia de caracteres de estilo C.

```
operator PXSTR() throw();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro de caractere para dados da cadeia de caracteres.

### <a name="remarks"></a>Comentários

Chame essa função para retornar um ponteiro para o buffer de caracteres de um objeto de cadeia de caracteres. O desenvolvedor pode alterar o conteúdo do objeto de cadeia de caracteres com este ponteiro.

##  <a name="pcxstr"></a>  CStrBufT::PCXSTR

Um ponteiro para uma cadeia de caracteres constante.

```
typedef CSimpleStringT<TCharType>::PCXSTR PCXSTR;
```

##  <a name="pxstr"></a>  CStrBufT::PXSTR

Um ponteiro para uma cadeia de caracteres.

```
typedef CSimpleStringT<TCharType>::PXSTR PXSTR;
```

##  <a name="set_length"></a>  CStrBufT::SET_LENGTH

Definir o tamanho do objeto de cadeia de caracteres no `GetBuffer` tempo.

```
static const DWORD SET_LENGTH = 0x02;
```

### <a name="remarks"></a>Comentários

Defina o comprimento do objeto de cadeia de caracteres em tempo de GetBuffer.

Determina se [CSimpleStringT::GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) e [CSimpleStringT::GetBufferSetLength](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffersetlength) são chamados quando o objeto de buffer de cadeia de caracteres é construído.

##  <a name="setlength"></a>  CStrBufT::SetLength

Define o comprimento do buffer de caracteres.

```
void SetLength(int nLength);
```

### <a name="parameters"></a>Parâmetros

*nLength*<br/>
O novo tamanho do buffer de caractere do objeto de cadeia de caracteres.

> [!NOTE]
>  Deve ser menor ou igual ao comprimento de buffer mínimo especificado no construtor de `CStrBufT`.

### <a name="remarks"></a>Comentários

Chame essa função para definir o comprimento da cadeia de caracteres representada pelo objeto de buffer.

##  <a name="stringtype"></a>  CStrBufT::StringType

O tipo de cadeia de caracteres cujo buffer deve ser manipulado por especializações desse modelo de classe.

```
typedef CSimpleStringT<TCharType> StringType;
```

### <a name="remarks"></a>Comentários

`TCharType` o tipo de caractere é usado para especializar o modelo de classe.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
