---
title: Classe CDumpContext
ms.date: 11/04/2016
f1_keywords:
- CDumpContext
- AFX/CDumpContext
- AFX/CDumpContext::CDumpContext
- AFX/CDumpContext::DumpAsHex
- AFX/CDumpContext::Flush
- AFX/CDumpContext::GetDepth
- AFX/CDumpContext::HexDump
- AFX/CDumpContext::SetDepth
helpviewer_keywords:
- CDumpContext [MFC], CDumpContext
- CDumpContext [MFC], DumpAsHex
- CDumpContext [MFC], Flush
- CDumpContext [MFC], GetDepth
- CDumpContext [MFC], HexDump
- CDumpContext [MFC], SetDepth
ms.assetid: 98c52b2d-14b5-48ed-b423-479a4d1c60fa
ms.openlocfilehash: 3a81e06586e6de14d57ce4c4de36dc30c73383f1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212508"
---
# <a name="cdumpcontext-class"></a>Classe CDumpContext

Dá suporte à saída de diagnóstico orientado a fluxo na forma de texto legível.

## <a name="syntax"></a>Sintaxe

```
class CDumpContext
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDumpContext::CDumpContext](#cdumpcontext)|Constrói um objeto `CDumpContext`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDumpContext::D umpAsHex](#dumpashex)|Despeja o item indicado no formato hexadecimal.|
|[CDumpContext:: flush](#flush)|Libera todos os dados no buffer de contexto de despejo.|
|[CDumpContext:: getdepth](#getdepth)|Obtém um inteiro correspondente à profundidade do despejo.|
|[CDumpContext::HexDump](#hexdump)|Despeja bytes contidos em uma matriz no formato hexadecimal.|
|[CDumpContext:: SetDepth](#setdepth)|Define a profundidade do despejo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CDumpContext::&lt;&lt;](#operator_lt_lt)|Insere variáveis e objetos no contexto de despejo.|

## <a name="remarks"></a>Comentários

`CDumpContext`Não tem uma classe base.

Você pode usar [afxDump](diagnostic-services.md#afxdump), um objeto predeclarado `CDumpContext` , para a maior parte do despejo. O `afxDump` objeto está disponível somente na versão de depuração do biblioteca MFC.

Vários dos serviços de [diagnóstico](../../mfc/reference/diagnostic-services.md) de memória usam `afxDump` para sua saída.

No ambiente do Windows, a saída do objeto predefinido `afxDump` , conceitualmente semelhante ao `cerr` fluxo, é roteada para o depurador por meio da função do Windows `OutputDebugString` .

A `CDumpContext` classe tem um **<<** operador de inserção () sobrecarregado para `CObject` ponteiros que despeja os dados do objeto. Se você precisar de um formato de despejo personalizado para um objeto derivado, substitua [CObject::D UMP](../../mfc/reference/cobject-class.md#dump). A maioria das classes do Microsoft Foundation implementa uma função de membro substituída `Dump` .

As classes que não são derivadas do `CObject` , como `CString` , `CTime` e `CTimeSpan` têm seus próprios operadores de inserção sobrecarregados `CDumpContext` , assim como as estruturas usadas com frequência, como `CFileStatus` , `CPoint` e `CRect` .

Se você usar a macro [IMPLEMENT_DYNAMIC](../../mfc/reference/run-time-object-model-services.md#implement_dynamic) ou [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial) na implementação de sua classe, `CObject::Dump` o nome da sua classe derivada será impresso `CObject` . Caso contrário, ele será impresso `CObject` .

A `CDumpContext` classe está disponível com as versões de depuração e de lançamento da biblioteca, mas a `Dump` função de membro é definida somente na versão de depuração. Use **#ifdef _DEBUG**  /  `#endif` instruções para colocar o código de diagnóstico entre colchetes, incluindo suas `Dump` funções de membro personalizadas.

Antes de criar seu próprio `CDumpContext` objeto, você deve criar um `CFile` objeto que serve como o destino do despejo.

Para obter mais informações sobre o `CDumpContext` , consulte [Debugging MFC Applications](/visualstudio/debugger/mfc-debugging-techniques).

**#define _DEBUG**

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CDumpContext`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="cdumpcontextcdumpcontext"></a><a name="cdumpcontext"></a>CDumpContext::CDumpContext

Constrói um objeto da classe `CDumpContext` .

```
CDumpContext(CFile* pFile = NULL);
```

### <a name="parameters"></a>parâmetros

*pFile*<br/>
Um ponteiro para o `CFile` objeto que é o destino de despejo.

### <a name="remarks"></a>Comentários

O `afxDump` objeto é construído automaticamente.

Não gravar no subjacente `CFile` enquanto o contexto de despejo estiver ativo; caso contrário, você interferirá com o despejo. No ambiente do Windows, a saída é roteada para o depurador por meio da função do Windows `OutputDebugString` .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#12](../../mfc/codesnippet/cpp/cdumpcontext-class_1.cpp)]

## <a name="cdumpcontextdumpashex"></a><a name="dumpashex"></a>CDumpContext::D umpAsHex

Despeja o tipo especificado formatado como números hexadecimais.

```
CDumpContext& DumpAsHex(BYTE b);
CDumpContext& DumpAsHex(DWORD dw);
CDumpContext& DumpAsHex(int n);
CDumpContext& DumpAsHex(LONG l);
CDumpContext& DumpAsHex(LONGLONG n);
CDumpContext& DumpAsHex(UINT u);
CDumpContext& DumpAsHex(ULONGLONG n);
CDumpContext& DumpAsHex(WORD w);
```

### <a name="return-value"></a>Valor retornado

Uma referência a um objeto `CDumpContext`.

### <a name="remarks"></a>Comentários

Chame essa função de membro para despejar o item do tipo especificado como um número hexadecimal. Para despejar uma matriz, chame [CDumpContext:: hexdump](#hexdump).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#13](../../mfc/codesnippet/cpp/cdumpcontext-class_2.cpp)]

## <a name="cdumpcontextflush"></a><a name="flush"></a>CDumpContext:: flush

Força todos os dados restantes nos buffers a serem gravados no arquivo anexado ao contexto de despejo.

```cpp
void Flush();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#14](../../mfc/codesnippet/cpp/cdumpcontext-class_3.cpp)]

## <a name="cdumpcontextgetdepth"></a><a name="getdepth"></a>CDumpContext:: getdepth

Determina se um despejo profundo ou superficial está em andamento.

```
int GetDepth() const;
```

### <a name="return-value"></a>Valor retornado

A profundidade do despejo, conforme definido por `SetDepth` .

### <a name="example"></a>Exemplo

  Consulte o exemplo de [SetDepth](#setdepth).

## <a name="cdumpcontexthexdump"></a><a name="hexdump"></a>CDumpContext::HexDump

Despeja uma matriz de bytes formatados como números hexadecimais.

```cpp
void HexDump(
    LPCTSTR lpszLine,
    BYTE* pby,
    int nBytes,
    int nWidth);
```

### <a name="parameters"></a>parâmetros

*lpszLine*<br/>
Uma cadeia de caracteres para saída no início de uma nova linha.

*pby*<br/>
Um ponteiro para um buffer que contém os bytes a serem despejados.

*nBytes*<br/>
O número de bytes a serem despejados.

*nWidth*<br/>
Número máximo de bytes despejados por linha (não a largura da linha de saída).

### <a name="remarks"></a>Comentários

Para despejar um único tipo de item específico como um número hexadecimal, chame [CDumpContext::D umpashex](#dumpashex).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#15](../../mfc/codesnippet/cpp/cdumpcontext-class_4.cpp)]

## <a name="cdumpcontextoperator-ltlt"></a><a name="operator_lt_lt"></a>Operador CDumpContext::&lt;&lt;

Gera os dados especificados para o contexto de despejo.

```
CDumpContext& operator<<(const CObject* pOb);
CDumpContext& operator<<(const CObject& ob);
CDumpContext& operator<<(LPCTSTR lpsz);
CDumpContext& operator<<(const void* lp);
CDumpContext& operator<<(BYTE by);
CDumpContext& operator<<(WORD w);
CDumpContext& operator<<(DWORD dw);
CDumpContext& operator<<(int n);
CDumpContext& operator<<(double d);
CDumpContext& operator<<(float f);
CDumpContext& operator<<(LONG l);
CDumpContext& operator<<(UINT u);
CDumpContext& operator<<(LPCWSTR lpsz);
CDumpContext& operator<<(LPCSTR lpsz);
CDumpContext& operator<<(LONGLONG n);
CDumpContext& operator<<(ULONGLONG n);
CDumpContext& operator<<(HWND h);
CDumpContext& operator<<(HDC h);
CDumpContext& operator<<(HMENU h);
CDumpContext& operator<<(HACCEL h);
CDumpContext& operator<<(HFONT h);
```

### <a name="return-value"></a>Valor retornado

Uma referência a `CDumpContext`. Usando o valor de retorno, você pode escrever várias inserções em uma única linha de código-fonte.

### <a name="remarks"></a>Comentários

O operador de inserção é sobrecarregado para `CObject` ponteiros, bem como para a maioria dos tipos primitivos. Um ponteiro para o caractere resulta em um despejo de conteúdo da cadeia de caracteres; um ponteiro para **`void`** resulta em um despejo hexadecimal apenas do endereço. Um LONGLONG resulta em um despejo de um inteiro com sinal de 64 bits; Um ULONGLONG resulta em um despejo de um inteiro sem sinal de 64 bits.

Se você usar a macro IMPLEMENT_DYNAMIC ou IMPLEMENT_SERIAL na implementação de sua classe, o operador de inserção, por meio do `CObject::Dump` , imprimirá o nome da sua `CObject` classe derivada. Caso contrário, ele será impresso `CObject` . Se você substituir a `Dump` função da classe, poderá fornecer uma saída mais significativa do conteúdo do objeto em vez de um despejo hexadecimal.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#17](../../mfc/codesnippet/cpp/cdumpcontext-class_5.cpp)]

## <a name="cdumpcontextsetdepth"></a><a name="setdepth"></a>CDumpContext:: SetDepth

Define a profundidade para o despejo.

```cpp
void SetDepth(int nNewDepth);
```

### <a name="parameters"></a>parâmetros

*nNewDepth*<br/>
O novo valor de profundidade.

### <a name="remarks"></a>Comentários

Se você estiver despejando um tipo primitivo ou simples `CObject` que não contenha ponteiros para outros objetos, um valor de 0 será suficiente. Um valor maior que 0 especifica um despejo profundo em que todos os objetos são despejados recursivamente. Por exemplo, um despejo profundo de uma coleção irá despejar todos os elementos da coleção. Você pode usar outros valores de profundidade específicos em suas classes derivadas.

> [!NOTE]
> Referências circulares não são detectadas em despejos profundos e podem resultar em loops infinitos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#16](../../mfc/codesnippet/cpp/cdumpcontext-class_6.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe de testcfile](../../mfc/reference/cfile-class.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)
