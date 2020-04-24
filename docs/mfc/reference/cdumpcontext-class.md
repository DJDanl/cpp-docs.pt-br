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
ms.openlocfilehash: e89bbc5f263dc9303140e43914619090109b8315
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753214"
---
# <a name="cdumpcontext-class"></a>Classe CDumpContext

Suporta a saída de diagnóstico orientada a fluxo na forma de texto legível por humanos.

## <a name="syntax"></a>Sintaxe

```
class CDumpContext
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CdumpContext::CDumpContext](#cdumpcontext)|Constrói um objeto `CDumpContext`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDumpContext::DumpAsHex](#dumpashex)|Despeja o item indicado no formato hexadecimal.|
|[CDumpContext::Flush](#flush)|Libera qualquer dado no buffer de contexto de despejo.|
|[CdumpContext::GetDepth](#getdepth)|Obtém um inteiro correspondente à profundidade do lixão.|
|[CDumpContext::HexDump](#hexdump)|Dumps bytes contidos em uma matriz em formato hexadecimal.|
|[CdumpContext::SetDepth](#setdepth)|Define a profundidade do lixão.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDumpContext::operador&lt;&lt;](#operator_lt_lt)|Insere variáveis e objetos no contexto do dump.|

## <a name="remarks"></a>Comentários

`CDumpContext`não tem uma classe base.

Você pode usar [afxDump](diagnostic-services.md#afxdump), `CDumpContext` um objeto pré-declarado, para a maior parte do seu dumping. O `afxDump` objeto está disponível apenas na versão Debug da Microsoft Foundation Class Library.

Vários dos [serviços](../../mfc/reference/diagnostic-services.md) `afxDump` de diagnóstico de memória usam para sua saída.

No ambiente Windows, a saída `afxDump` do objeto predefinido, `cerr` conceitualmente semelhante ao fluxo, é roteada para o depurador através da função `OutputDebugString`Windows .

A `CDumpContext` classe tem um **<<** operador de `CObject` inserção sobrecarregado ( ) para ponteiros que despeja os dados do objeto. Se você precisar de um formato de despejo personalizado para um objeto derivado, anule [CObject::Dump](../../mfc/reference/cobject-class.md#dump). A maioria das classes da `Dump` Microsoft Foundation implementam uma função de membro substituída.

Classes que não são `CObject`derivadas, `CTime`tais `CTimeSpan`como `CString`, e `CDumpContext` , têm seus próprios operadores `CFileStatus` `CPoint`de `CRect`inserção sobrecarregados, assim como estruturas muitas vezes utilizadas, como , e .

Se você usar a [macro IMPLEMENT_DYNAMIC](../../mfc/reference/run-time-object-model-services.md#implement_dynamic) ou [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial) `CObject::Dump` na implementação de `CObject`sua classe, então imprimirá o nome da sua classe derivada. Caso contrário, ele `CObject`vai imprimir .

A `CDumpContext` classe está disponível com as versões Debug e Release da biblioteca, mas a `Dump` função de membro é definida apenas na versão Debug. Use **#ifdef _DEBUG**  /  `#endif` instruções para suporte `Dump` ao seu código de diagnóstico, incluindo suas funções de membro personalizados.

Antes de criar `CDumpContext` seu próprio objeto, você deve criar um `CFile` objeto que serve como destino de despejo.

Para obter `CDumpContext`mais informações sobre , consulte [Depuração de aplicativos MFC](/visualstudio/debugger/mfc-debugging-techniques).

**#define _DEBUG #define**

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CDumpContext`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="cdumpcontextcdumpcontext"></a><a name="cdumpcontext"></a>CdumpContext::CDumpContext

Constrói um objeto `CDumpContext`de classe.

```
CDumpContext(CFile* pFile = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pfile*<br/>
Um ponteiro `CFile` para o objeto que é o destino do despejo.

### <a name="remarks"></a>Comentários

O `afxDump` objeto é construído automaticamente.

Não escreva para o `CFile` subjacente enquanto o contexto de despejo estiver ativo; caso contrário, você vai interferir com o lixo. No ambiente Windows, a saída é roteada para `OutputDebugString`o depurador através da função Windows .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#12](../../mfc/codesnippet/cpp/cdumpcontext-class_1.cpp)]

## <a name="cdumpcontextdumpashex"></a><a name="dumpashex"></a>CDumpContext::DumpAsHex

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

Chame esta função de membro para despejar o item do tipo especificado como um número hexadecimal. Para despejar uma matriz, ligue para [CDumpContext::HexDump](#hexdump).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#13](../../mfc/codesnippet/cpp/cdumpcontext-class_2.cpp)]

## <a name="cdumpcontextflush"></a><a name="flush"></a>CDumpContext::Flush

Força que quaisquer dados restantes em buffers sejam gravados no arquivo anexado ao contexto de despejo.

```cpp
void Flush();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#14](../../mfc/codesnippet/cpp/cdumpcontext-class_3.cpp)]

## <a name="cdumpcontextgetdepth"></a><a name="getdepth"></a>CdumpContext::GetDepth

Determina se um despejo profundo ou raso está em processo.

```
int GetDepth() const;
```

### <a name="return-value"></a>Valor retornado

A profundidade do despejo `SetDepth`como definido por .

### <a name="example"></a>Exemplo

  Veja o exemplo de [SetDepth](#setdepth).

## <a name="cdumpcontexthexdump"></a><a name="hexdump"></a>CDumpContext::HexDump

Despeja uma matriz de bytes formatados como números hexadecimais.

```cpp
void HexDump(
    LPCTSTR lpszLine,
    BYTE* pby,
    int nBytes,
    int nWidth);
```

### <a name="parameters"></a>Parâmetros

*lpszLine*<br/>
Uma seqüência para saída no início de uma nova linha.

*pby*<br/>
Um ponteiro para um buffer contendo os bytes para despejar.

*Nbytes*<br/>
O número de bytes para despejar.

*Nwidth*<br/>
Número máximo de bytes despejados por linha (não a largura da linha de saída).

### <a name="remarks"></a>Comentários

Para despejar um único tipo de item específico como um número hexadecimal, ligue para [CDumpContext::DumpAsHex](#dumpashex).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#15](../../mfc/codesnippet/cpp/cdumpcontext-class_4.cpp)]

## <a name="cdumpcontextoperator-ltlt"></a><a name="operator_lt_lt"></a>CDumpContext::operador&lt;&lt;

Produz os dados especificados para o contexto de despejo.

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

O operador de inserção está sobrecarregado para `CObject` ponteiros, bem como para a maioria dos tipos primitivos. Um ponteiro para o caractere resulta em um despejo de conteúdo de seqüência; um ponteiro para **anular** resulta em um despejo hexadecimal apenas do endereço. Um LONGLONG resulta em um despejo de um inteiro assinado de 64 bits; Um ULONGLONG resulta em um despejo de um inteiro não assinado de 64 bits.

Se você usar o IMPLEMENT_DYNAMIC ou IMPLEMENT_SERIAL macro na implementação `CObject::Dump`de sua classe, `CObject`então o operador de inserção, através de , imprimirá o nome da sua classe derivada. Caso contrário, ele `CObject`vai imprimir . Se você anular `Dump` a função da classe, então você pode fornecer uma saída mais significativa do conteúdo do objeto em vez de um despejo hexadecimal.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#17](../../mfc/codesnippet/cpp/cdumpcontext-class_5.cpp)]

## <a name="cdumpcontextsetdepth"></a><a name="setdepth"></a>CdumpContext::SetDepth

Define a profundidade para o despejo.

```cpp
void SetDepth(int nNewDepth);
```

### <a name="parameters"></a>Parâmetros

*nNewDepth*<br/>
O novo valor de profundidade.

### <a name="remarks"></a>Comentários

Se você está despejando `CObject` um tipo primitivo ou simples que não contém ponteiros para outros objetos, então um valor de 0 é suficiente. Um valor maior que 0 especifica um despejo profundo onde todos os objetos são despejados recursivamente. Por exemplo, um despejo profundo de uma coleção vai despejar todos os elementos da coleção. Você pode usar outros valores de profundidade específicos em suas classes derivadas.

> [!NOTE]
> Referências circulares não são detectadas em lixões profundos e podem resultar em loops infinitos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#16](../../mfc/codesnippet/cpp/cdumpcontext-class_6.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)
