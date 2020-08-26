---
title: Serviços de diagnóstico
ms.date: 11/04/2016
helpviewer_keywords:
- diagnosi [MFC]s, diagnostic services
- diagnostic macros [MFC], list of general MFC
- services [MFC], diagnostic
- MFC, diagnostic services
- general diagnostic functions and variables [MFC]
- diagnostics [MFC], diagnostic functions and variables
- diagnostics [MFC], list of general MFC
- diagnosis [MFC], diagnostic functions and variables
- diagnosis [MFC], list of general MFC
- general diagnostic macros in MFC
- diagnostic macros [MFC]
- diagnostic services [MFC]
- object diagnostic functions in MFC
- diagnostics [MFC], diagnostic services
- diagnostic functions and variables [MFC]
ms.assetid: 8d78454f-9fae-49c2-88c9-d3fabd5393e8
ms.openlocfilehash: 931545e6a79ecaa59d147e48265649ef20466fbd
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88837392"
---
# <a name="diagnostic-services"></a>Serviços de diagnóstico

O biblioteca MFC fornece muitos serviços de diagnóstico que facilitam a depuração de seus programas. Esses serviços de diagnóstico incluem macros e funções globais que permitem controlar as alocações de memória do programa, despejar o conteúdo dos objetos durante o tempo de execução e imprimir mensagens de depuração durante o tempo de execução. As macros e funções globais dos serviços de diagnóstico são agrupadas nas seguintes categorias:

- Macros de diagnóstico gerais

- Funções e variáveis de diagnóstico gerais

- Funções de diagnóstico de objeto

Essas macros e funções estão disponíveis para todas as classes derivadas das `CObject` versões de depuração e de lançamento do MFC. No entanto, tudo isso, exceto DEBUG_NEW e verificar, não faz nada na versão de lançamento.

Na biblioteca de depuração, todos os blocos de memória alocados estão entre colchetes com uma série de "bytes de proteção". Se esses bytes forem incomodados por uma gravação de memória errônea, as rotinas de diagnóstico poderão relatar um problema. Se você incluir a linha:

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/diagnostic-services_1.cpp)]

no arquivo de implementação, todas as chamadas para **`new`** armazenarão o nome de arquivo e o número de linha em que a alocação de memória ocorreu. A função [CMemoryState::D umpallobjectssince](cmemorystate-structure.md#dumpallobjectssince) exibirá essas informações adicionais, permitindo que você identifique os vazamentos de memória. Consulte também a classe [CDumpContext](../../mfc/reference/cdumpcontext-class.md) para obter informações adicionais sobre a saída de diagnóstico.

Além disso, a biblioteca de tempo de execução do C também dá suporte a um conjunto de funções de diagnóstico que você pode usar para depurar seus aplicativos. Para obter mais informações, consulte [Depurar rotinas](../../c-runtime-library/debug-routines.md) na referência da biblioteca de tempo de execução.

### <a name="mfc-general-diagnostic-macros"></a>Macros de diagnóstico geral do MFC

|Nome|Descrição|
|-|-|
|[DECLARAR](#assert)|Imprime uma mensagem e, em seguida, anula o programa se a expressão especificada for avaliada como FALSE na versão de depuração da biblioteca.|
|[ASSERT_KINDOF](#assert_kindof)|Testa se um objeto é um objeto da classe especificada ou de uma classe derivada da classe especificada.|
|[ASSERT_VALID](#assert_valid)|Testa a validade interna de um objeto chamando sua `AssertValid` função de membro; normalmente substituído de `CObject` .|
|[DEBUG_NEW](#debug_new)|Fornece um nome de arquivo e um número de linha para todas as alocações de objeto no modo de depuração para ajudar a encontrar vazamentos de memória.|
|[DEBUG_ONLY](#debug_only)|Semelhante a ASSERT, mas não testa o valor da expressão; útil para o código que deve ser executado somente no modo de depuração.|
|[GARANTIR e ENSURE_VALID](#ensure)|Use para validar a exatidão dos dados.|
|[THIS_FILE](#this_file)|Expande para o nome do arquivo que está sendo compilado.|
|[RASTREOU](#trace)|`printf`A funcionalidade do é semelhante na versão de depuração da biblioteca.|
|[Confirme](#verify)|Semelhante a ASSERT, mas avalia a expressão na versão de lançamento da biblioteca, bem como na versão de depuração.|

### <a name="mfc-general-diagnostic-variables-and-functions"></a>Variáveis e funções de diagnóstico geral do MFC

|Nome|Descrição|
|-|-|
|[afxDump](#afxdump)|Variável global que envia informações de [CDumpContext](../../mfc/reference/cdumpcontext-class.md) para a janela de saída do depurador ou para o terminal de depuração.|
|[afxMemDF](#afxmemdf)|Variável global que controla o comportamento do alocador de memória de depuração.|
|[AfxCheckError](#afxcheckerror)|Variável global usada para testar o SCODE passado para ver se é um erro e, em caso afirmativo, gera o erro apropriado.|
|[AfxCheckMemory](#afxcheckmemory)|Verifica a integridade de toda a memória alocada no momento.|
|[AfxDebugBreak](#afxdebugbreak)|Causa uma interrupção na execução.|
|[AfxDump](#cdumpcontext_in_mfc)|Se chamado enquanto estiver no depurador, o despeja o estado de um objeto durante a depuração.|
|[AfxDump](#afxdump)|Função interna que despeja o estado de um objeto durante a depuração.|
|[AfxDumpStack](#afxdumpstack)|Gerar uma imagem da pilha atual. Essa função está sempre vinculada estaticamente.|
|[AfxEnableMemoryLeakDump](#afxenablememoryleakdump)|Habilita o despejo de vazamento de memória.|
|[AfxEnableMemoryTracking](#afxenablememorytracking)|Ativa e desativa o controle de memória.|
|[AfxIsMemoryBlock](#afxismemoryblock)|Verifica se um bloco de memória foi alocado corretamente.|
|[AfxIsValidAddress](#afxisvalidaddress)|Verifica se um intervalo de endereços de memória está dentro dos limites do programa.|
|[AfxIsValidString](#afxisvalidstring)|Determina se um ponteiro para uma cadeia de caracteres é válido.|
|[AfxSetAllocHook](#afxsetallochook)|Habilita a chamada de uma função em cada alocação de memória.|

### <a name="mfc-object-diagnostic-functions"></a>Funções de diagnóstico de objeto MFC

|Nome|Descrição|
|-|-|
|[AfxDoForAllClasses](#afxdoforallclasses)|Executa uma função especificada em todas as `CObject` classes derivadas que dão suporte à verificação de tipo em tempo de execução.|
|[AfxDoForAllObjects](#afxdoforallobjects)|Executa uma função especificada em todos os `CObject` objetos derivados que foram alocados com o **`new`** .|

### <a name="mfc-compilation-macros"></a>Macros de compilação do MFC

|Nome|Descrição|
|-|-|
|[_AFX_SECURE_NO_WARNINGS](#afx_secure_no_warnings)|Suprime avisos do compilador para o uso de funções do MFC preteridas.|

## <a name="_afx_secure_no_warnings"></a><a name="afx_secure_no_warnings"></a> _AFX_SECURE_NO_WARNINGS

Suprime avisos do compilador para o uso de funções do MFC preteridas.

### <a name="syntax"></a>Sintaxe

```
_AFX_SECURE_NO_WARNINGS
```

### <a name="example"></a>Exemplo

Este exemplo de código causaria um aviso do compilador se _AFX_SECURE_NO_WARNINGS não fosse definido.

```cpp
// define this before including any afx files in *pch.h* (*stdafx.h* in Visual Studio 2017 and earlier)
#define _AFX_SECURE_NO_WARNINGS
```

```cpp
CRichEditCtrl* pRichEdit = new CRichEditCtrl;
pRichEdit->Create(WS_CHILD|WS_VISIBLE|WS_BORDER|ES_MULTILINE,
   CRect(10,10,100,200), pParentWnd, 1);
char sz[256];
pRichEdit->GetSelText(sz);
```

## <a name="afxdebugbreak"></a><a name="afxdebugbreak"></a> AfxDebugBreak

Chame essa função para causar uma interrupção (no local da chamada para `AfxDebugBreak` ) na execução da versão de depuração do seu aplicativo MFC.

### <a name="syntax"></a>Sintaxe

```cpp
void AfxDebugBreak( );
```

### <a name="remarks"></a>Comentários

`AfxDebugBreak` Não tem nenhum efeito nas versões de lançamento de um aplicativo MFC e deve ser removido. Essa função só deve ser usada em aplicativos MFC. Use a versão da API do Win32, `DebugBreak` , para causar uma interrupção em aplicativos não MFC.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxver_. h

## <a name="assert"></a><a name="assert"></a> DECLARAR

Avalia seu argumento.

```
ASSERT(booleanExpression)
```

### <a name="parameters"></a>parâmetros

*valor booliano*<br/>
Especifica uma expressão (incluindo valores de ponteiro) que é avaliada como zero ou 0.

### <a name="remarks"></a>Comentários

Se o resultado for 0, a macro imprime uma mensagem de diagnóstico e anula o programa. Se a condição for diferente de zero, ela não fará nada.

A mensagem de diagnóstico tem o formato

`assertion failed in file <name> in line <num>`

em que *Name* é o nome do arquivo de origem e *num* é o número de linha da asserção que falhou no arquivo de origem.

Na versão de lançamento do MFC, ASSERT não avalia a expressão e, portanto, não interromperá o programa. Se a expressão precisar ser avaliada independentemente do ambiente, use a macro VERIFY em vez de ASSERT.

> [!NOTE]
> Essa função está disponível somente na versão de depuração do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#44](../../mfc/codesnippet/cpp/diagnostic-services_2.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="assert_kindof"></a><a name="assert_kindof"></a> ASSERT_KINDOF

Essa macro declara que o objeto apontado é um objeto da classe especificada ou é um objeto de uma classe derivada da classe especificada.

```
ASSERT_KINDOF(classname, pobject)
```

### <a name="parameters"></a>parâmetros

*ClassName*<br/>
O nome de uma `CObject` classe derivada.

*pobject*<br/>
Um ponteiro para um objeto de classe.

### <a name="remarks"></a>Comentários

O parâmetro *pObject* deve ser um ponteiro para um objeto e pode ser **`const`** . O objeto apontado para e a classe deve dar suporte a `CObject` informações de classe em tempo de execução. Por exemplo, para garantir que `pDocument` seja um ponteiro para um objeto da `CMyDoc` classe, ou qualquer um de seus derivados, você poderia codificar:

[!code-cpp[NVC_MFCDocView#194](../../mfc/codesnippet/cpp/diagnostic-services_3.cpp)]

O uso da `ASSERT_KINDOF` macro é exatamente o mesmo que a codificação:

[!code-cpp[NVC_MFCDocView#195](../../mfc/codesnippet/cpp/diagnostic-services_4.cpp)]

Essa função funciona somente para classes declaradas com a macro [DECLARE_DYNAMIC] (Runtime-time-Object-Model-Services. MD # declare_dynamic ou [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) .

> [!NOTE]
> Essa função está disponível somente na versão de depuração do MFC.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="assert_valid"></a><a name="assert_valid"></a> ASSERT_VALID

Use para testar suas suposições sobre a validade do estado interno de um objeto.

```
ASSERT_VALID(pObject)
```

### <a name="parameters"></a>parâmetros

*pObject*<br/>
Especifica um objeto de uma classe derivada de `CObject` que tem uma versão de substituição da `AssertValid` função membro.

### <a name="remarks"></a>Comentários

ASSERT_VALID chama a `AssertValid` função de membro do objeto passado como seu argumento.

Na versão de lançamento do MFC, ASSERT_VALID não faz nada. Na versão de depuração, ele valida o ponteiro, verifica em relação a NULL e chama as funções de membro do próprio objeto `AssertValid` . Se qualquer um desses testes falhar, uma mensagem de alerta será exibida da mesma maneira que a [declaração](#assert).

> [!NOTE]
> Essa função está disponível somente na versão de depuração do MFC.

Para obter mais informações e exemplos, consulte [DEBUGGING MFC Applications](/visualstudio/debugger/mfc-debugging-techniques).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#19](../../mfc/codesnippet/cpp/diagnostic-services_5.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="debug_new"></a><a name="debug_new"></a> DEBUG_NEW

Ajuda na localização de vazamentos de memória.

```
#define  new DEBUG_NEW
```

### <a name="remarks"></a>Comentários

Você pode usar DEBUG_NEW em qualquer lugar em seu programa que normalmente usaria o **`new`** operador para alocar o armazenamento de heap.

No modo de depuração (quando o símbolo de **_DEBUG** é definido), DEBUG_NEW controla o nome do arquivo e o número da linha para cada objeto que ele aloca. Em seguida, quando você usa a função de membro [CMemoryState::D umpallobjectssince](cmemorystate-structure.md#dumpallobjectssince) , cada objeto alocado com DEBUG_NEW é mostrado com o nome de arquivo e o número de linha onde ele foi alocado.

Para usar DEBUG_NEW, insira a diretiva a seguir em seus arquivos de origem:

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/diagnostic-services_1.cpp)]

Depois de inserir essa diretiva, o pré-processador inserirá DEBUG_NEW sempre que você usar **`new`** , e o MFC fará o resto. Quando você compila uma versão de lançamento do seu programa, DEBUG_NEW é resolvido para uma **`new`** operação simples e as informações de nome de arquivo e de linha não são geradas.

> [!NOTE]
> Nas versões anteriores do MFC (4,1 e anteriores), você precisava colocar a `#define` instrução após todas as instruções que chamaram as macros IMPLEMENT_DYNCREATE ou IMPLEMENT_SERIAL. Isso não é mais necessário.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="debug_only"></a><a name="debug_only"></a> DEBUG_ONLY

No modo de depuração (quando o símbolo de **_DEBUG** é definido), DEBUG_ONLY avalia seu argumento.

```
DEBUG_ONLY(expression)
```

### <a name="remarks"></a>Comentários

Em uma compilação de versão, DEBUG_ONLY não avalia seu argumento. Isso é útil quando você tem código que deve ser executado somente em compilações de depuração.

A macro DEBUG_ONLY é equivalente à *expressão* ao redor com `#ifdef _DEBUG` and `#endif` .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#32](../../mfc/codesnippet/cpp/diagnostic-services_6.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

### <a name="ensure-and-ensure_valid"></a><a name="ensure"></a> GARANTIR e ENSURE_VALID

Use para validar a exatidão dos dados.

### <a name="syntax"></a>Sintaxe

```
ENSURE(  booleanExpression )
ENSURE_VALID( booleanExpression  )
```

### <a name="parameters"></a>parâmetros

*valor booliano*<br/>
Especifica uma expressão booliana a ser testada.

### <a name="remarks"></a>Comentários

A finalidade dessas macros é melhorar a validação dos parâmetros. As macros impedem o processamento adicional de parâmetros incorretos em seu código. Ao contrário das macros ASSERT, as macros If geram uma exceção além da geração de uma asserção.

As macros se comportam de duas maneiras, de acordo com a configuração do projeto. As macros chamam ASSERT e, em seguida, geram uma exceção se a asserção falhar. Portanto, em configurações de depuração (ou seja, onde _DEBUG é definido) as macros produzem uma asserção e uma exceção durante as configurações de versão, as macros produzem apenas a exceção (ASSERT não avalia a expressão nas configurações de versão).

A macro ENSURE_ARG funciona como a macro If.

ENSURE_VALID chama a macro ASSERT_VALID (que tem efeito somente em compilações de depuração). Além disso, ENSURE_VALID lançará uma exceção se o ponteiro for nulo. O teste nulo é executado nas configurações de depuração e de versão.

Se qualquer um desses testes falhar, uma mensagem de alerta será exibida da mesma maneira que a declaração. A macro gera uma exceção de argumento inválida, se necessário.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="this_file"></a><a name="this_file"></a> THIS_FILE

Expande para o nome do arquivo que está sendo compilado.

### <a name="syntax"></a>Sintaxe

```
THIS_FILE
```

### <a name="remarks"></a>Comentários

As informações são usadas pelas macros ASSERT e VERIFY. O assistente de aplicativo e os assistentes de código colocam a macro em arquivos de código-fonte que criam.

### <a name="example"></a>Exemplo

```cpp
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// __FILE__ is one of the six predefined ANSI C macros that the
// compiler recognizes.
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="trace"></a><a name="trace"></a> RASTREOU

Envia a cadeia de caracteres especificada para o depurador do aplicativo atual.

```
TRACE(exp)
TRACE(DWORD  category,  UINT  level, LPCSTR lpszFormat, ...)
```

### <a name="remarks"></a>Comentários

Consulte [ATLTRACE2](../../atl/reference/debugging-and-error-reporting-macros.md#atltrace2) para obter uma descrição do Trace. TRACE e ATLTRACE2 têm o mesmo comportamento.

Na versão de depuração do MFC, essa macro envia a cadeia de caracteres especificada para o depurador do aplicativo atual. Em uma compilação de versão, essa macro é compilada para nada (nenhum código é gerado).

Para obter mais informações, consulte [DEBUGGING MFC Applications](/visualstudio/debugger/mfc-debugging-techniques).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="verify"></a><a name="verify"></a> Confirme

Na versão de depuração do MFC, o avalia seu argumento.

```
VERIFY(booleanExpression)
```

### <a name="parameters"></a>parâmetros

*valor booliano*<br/>
Especifica uma expressão (incluindo valores de ponteiro) que é avaliada como zero ou 0.

### <a name="remarks"></a>Comentários

Se o resultado for 0, a macro imprimirá uma mensagem de diagnóstico e interromperá o programa. Se a condição for diferente de zero, ela não fará nada.

A mensagem de diagnóstico tem o formato

`assertion failed in file <name> in line <num>`

em que *Name* é o nome do arquivo de origem e *num* é o número de linha da asserção que falhou no arquivo de origem.

Na versão de lançamento do MFC, a verificação avalia a expressão, mas não imprime nem interrompe o programa. Por exemplo, se a expressão for uma chamada de função, a chamada será feita.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#198](../../mfc/codesnippet/cpp/diagnostic-services_7.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxdump-cdumpcontext-in-mfc"></a><a name="cdumpcontext_in_mfc"></a> afxDump (CDumpContext na MFC)

Fornece a funcionalidade básica de despejo de objeto em seu aplicativo.

```
CDumpContext  afxDump;
```

### <a name="remarks"></a>Comentários

`afxDump` é um objeto [CDumpContext](../../mfc/reference/cdumpcontext-class.md) predefinido que permite que você envie `CDumpContext` informações para a janela de saída do depurador ou para um terminal de depuração. Normalmente, você fornece `afxDump` como um parâmetro para `CObject::Dump` .

No Windows NT e em todas as versões do Windows, a `afxDump` saída é enviada para a janela de depuração de saída do Visual C++ quando você depura seu aplicativo.

Essa variável é definida somente na versão de depuração do MFC. Para obter mais informações sobre o `afxDump` , consulte [Debugging MFC Applications](/visualstudio/debugger/mfc-debugging-techniques).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#23](../../mfc/codesnippet/cpp/diagnostic-services_8.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxdump-internal"></a><a name="afxdump"></a> AfxDump (interno)

Função interna que o MFC usa para despejar o estado de um objeto durante a depuração.

### <a name="syntax"></a>Sintaxe

```cpp
void AfxDump(const CObject* pOb);
```

### <a name="parameters"></a>parâmetros

*pOb*<br/>
Um ponteiro para um objeto de uma classe derivada de `CObject` .

### <a name="remarks"></a>Comentários

`AfxDump` chama a função de membro de um objeto `Dump` e envia as informações para o local especificado pela `afxDump` variável. `AfxDump` está disponível somente na versão de depuração do MFC.

O código do programa não deve chamar `AfxDump` , mas, em vez disso, deve chamar a `Dump` função de membro do objeto apropriado.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxmemdf"></a><a name="afxmemdf"></a> afxMemDF

Essa variável pode ser acessada de um depurador ou seu programa e permite que você ajuste o diagnóstico de alocação.

```
int  afxMemDF;
```

### <a name="remarks"></a>Comentários

`afxMemDF` pode ter os seguintes valores, conforme especificado pela enumeração `afxMemDF` :

- `allocMemDF` Ativa a depuração de alocador (configuração padrão na biblioteca de depuração).

- `delayFreeMemDF` Atrasa a memória livre. Enquanto o programa libera um bloco de memória, o alocador não retorna essa memória para o sistema operacional subjacente. Isso irá posicionar o máximo de estresse de memória em seu programa.

- `checkAlwaysMemDF` Chama `AfxCheckMemory` toda vez que a memória é alocada ou liberada. Isso irá reduzir significativamente as alocações de memória e desalocações.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#30](../../mfc/codesnippet/cpp/diagnostic-services_9.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxcheckerror"></a><a name="afxcheckerror"></a> AfxCheckError

Essa função testa o SCODE passado para ver se é um erro.

```cpp
void AFXAPI AfxCheckError(SCODE sc);
throw CMemoryException*
throw COleException*
```

### <a name="remarks"></a>Comentários

Se for um erro, a função lançará uma exceção. Se o SCODE passado for E_OUTOFMEMORY, a função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) chamando [AfxThrowMemoryException](exception-processing.md#afxthrowmemoryexception). Caso contrário, a função gera um [COleException](../../mfc/reference/coleexception-class.md) chamando [AfxThrowOleException](exception-processing.md#afxthrowoleexception).

Essa função pode ser usada para verificar os valores de retorno de chamadas para funções OLE em seu aplicativo. Ao testar o valor de retorno com essa função em seu aplicativo, você pode reagir adequadamente às condições de erro com uma quantidade mínima de código.

> [!NOTE]
> Essa função tem o mesmo efeito em compilações de depuração e não depuração.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#33](../../mfc/codesnippet/cpp/diagnostic-services_10.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxcheckmemory"></a><a name="afxcheckmemory"></a> AfxCheckMemory

Essa função valida o pool de memória livre e imprime mensagens de erro conforme necessário.

```
BOOL  AfxCheckMemory();
```

### <a name="return-value"></a>Valor Retornado

Diferente de zero se não houver erros de memória; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se a função não detectar corrupção de memória, ela não imprimirá nada.

Todos os blocos de memória alocados atualmente no heap são verificados, incluindo aqueles alocados por **`new`** , mas não aqueles alocados por chamadas diretas para alocadores de memória subjacentes, como a função **malloc** ou a `GlobalAlloc` função do Windows. Se algum bloco for encontrado como corrompido, uma mensagem será impressa na saída do depurador.

Se você incluir a linha

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/diagnostic-services_1.cpp)]

em um módulo de programa, as próximas chamadas para `AfxCheckMemory` mostrar o nome de arquivo e o número de linha em que a memória foi alocada.

> [!NOTE]
> Se o módulo contiver uma ou mais implementações de classes serializáveis, você deverá colocar a `#define` linha após a última IMPLEMENT_SERIAL chamada de macro.

Essa função funciona apenas na versão de depuração do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#26](../../mfc/codesnippet/cpp/diagnostic-services_11.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxdump-mfc"></a><a name="afxdump"></a> AfxDump (MFC)

Chame essa função enquanto estiver no depurador para despejar o estado de um objeto durante a depuração.

```cpp
void AfxDump(const CObject* pOb);
```

### <a name="parameters"></a>parâmetros

*pOb*<br/>
Um ponteiro para um objeto de uma classe derivada de `CObject` .

### <a name="remarks"></a>Comentários

`AfxDump` chama a função de membro de um objeto `Dump` e envia as informações para o local especificado pela `afxDump` variável. `AfxDump` está disponível somente na versão de depuração do MFC.

O código do programa não deve chamar `AfxDump` , mas, em vez disso, deve chamar a `Dump` função de membro do objeto apropriado.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxdumpstack"></a><a name="afxdumpstack"></a> AfxDumpStack

Essa função global pode ser usada para gerar uma imagem da pilha atual.

```cpp
void AFXAPI AfxDumpStack(DWORD dwTarget = AFX_STACK_DUMP_TARGET_DEFAULT);
```

### <a name="parameters"></a>parâmetros

*dwTarget*<br/>
Indica o destino da saída de despejo. Os valores possíveis, que podem ser combinados usando o operador OR-bit ( **&#124;**), são os seguintes:

- AFX_STACK_DUMP_TARGET_TRACE Envia a saída por meio da macro de [rastreamento](#trace) . A macro de rastreamento gera saída somente em compilações de depuração; Ele não gera nenhuma saída nas compilações de versão. Além disso, o rastreamento pode ser redirecionado para outros destinos além do depurador.

- AFX_STACK_DUMP_TARGET_DEFAULT envia a saída de despejo para o destino padrão. Para uma compilação de depuração, a saída vai para a macro de rastreamento. Em uma compilação de versão, a saída vai para a área de transferência.

- AFX_STACK_DUMP_TARGET_CLIPBOARD Envia a saída somente para a área de transferência. Os dados são colocados na área de transferência como texto sem formatação usando o formato de área de transferência CF_TEXT.

- AFX_STACK_DUMP_TARGET_BOTH envia a saída para a área de transferência e para a macro de rastreamento, simultaneamente.

- AFX_STACK_DUMP_TARGET_ODS envia a saída diretamente para o depurador por meio da função do Win32 `OutputDebugString()` . Essa opção gerará a saída do depurador em compilações de depuração e de versão quando um depurador é anexado ao processo. AFX_STACK_DUMP_TARGET_ODS sempre atinge o depurador (se estiver anexado) e não pode ser redirecionado.

### <a name="remarks"></a>Comentários

O exemplo a seguir reflete uma única linha da saída gerada pela chamada `AfxDumpStack` de um manipulador de botão em um aplicativo de caixa de diálogo do MFC:

```Output
=== begin AfxDumpStack output ===
00427D55: DUMP2\DEBUG\DUMP2.EXE! void AfxDumpStack(unsigned long) + 181 bytes
0040160B: DUMP2\DEBUG\DUMP2.EXE! void CDump2Dlg::OnClipboard(void) + 14 bytes
0044F884: DUMP2\DEBUG\DUMP2.EXE! int _AfxDispatchCmdMsg(class CCmdTarget *,
unsigned int,int,void ( CCmdTarget::*)(void),void *,unsigned int,struct
AFX_CMDHANDLE
0044FF7B: DUMP2\DEBUG\DUMP2.EXE! virtual int CCmdTarget::OnCmdMsg(unsigned
int,int,void *,struct AFX_CMDHANDLERINFO *) + 626 bytes
00450C71: DUMP2\DEBUG\DUMP2.EXE! virtual int CDialog::OnCmdMsg(unsigned
int,int,void *,struct AFX_CMDHANDLERINFO *) + 36 bytes
00455B27: DUMP2\DEBUG\DUMP2.EXE! virtual int CWnd::OnCommand(unsigned
int,long) + 312 bytes
00454D3D: DUMP2\DEBUG\DUMP2.EXE! virtual int CWnd::OnWndMsg(unsigned
int,unsigned int,long,long *) + 83 bytes
00454CC0: DUMP2\DEBUG\DUMP2.EXE! virtual long CWnd::WindowProc(unsigned
int,unsigned int,long) + 46 bytes
004528D9: DUMP2\DEBUG\DUMP2.EXE! long AfxCallWndProc(class CWnd *,struct
HWND__ *,unsigned int,unsigned int,long) + 237 bytes
00452D34: DUMP2\DEBUG\DUMP2.EXE! long AfxWndProc(struct HWND__ *,unsigned
int,unsigned int,long) + 129 bytes
BFF73663: WINDOWS\SYSTEM\KERNEL32.DLL! ThunkConnect32 + 2148 bytes
BFF928E0: WINDOWS\SYSTEM\KERNEL32.DLL! UTUnRegister + 2492 bytes
=== end AfxDumpStack() output ===
```

Cada linha na saída acima indica o endereço da última chamada de função, o nome do caminho completo do módulo que contém a chamada de função e o protótipo de função chamado. Se a chamada de função na pilha não acontecer no endereço exato da função, um deslocamento de bytes será mostrado.

Por exemplo, a tabela a seguir descreve a primeira linha da saída acima:

|Saída|Descrição|
|------------|-----------------|
|`00427D55:`|O endereço de retorno da última chamada de função.|
|`DUMP2\DEBUG\DUMP2.EXE!`|O nome do caminho completo do módulo que contém a chamada de função.|
|`void AfxDumpStack(unsigned long)`|O protótipo de função chamado.|
|`+ 181 bytes`|O deslocamento em bytes do endereço do protótipo de função (nesse caso, `void AfxDumpStack(unsigned long)` ) para o endereço de retorno (nesse caso, `00427D55` ).|

`AfxDumpStack` está disponível em versões de depuração e não-depuração das bibliotecas do MFC; no entanto, a função é sempre vinculada estaticamente, mesmo quando o arquivo executável usa MFC em uma DLL compartilhada. Em implementações de biblioteca compartilhada, a função é encontrada no MFCS42. Biblioteca LIB (e suas variantes).

Para usar essa função com êxito:

- O arquivo IMAGEHLP.DLL deve estar no seu caminho. Se você não tiver essa DLL, a função exibirá uma mensagem de erro. Consulte [biblioteca de ajuda de imagem](/windows/win32/Debug/image-help-library) para obter informações sobre o conjunto de funções fornecido pelo imagehlp.

- Os módulos que têm quadros na pilha devem incluir informações de depuração. Se eles não contiverem informações de depuração, a função ainda irá gerar um rastreamento de pilha, mas o rastreamento será menos detalhado.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxenablememoryleakdump"></a><a name="afxenablememoryleakdump"></a> AfxEnableMemoryLeakDump

Habilita e desabilita o despejo de vazamento de memória no destruidor AFX_DEBUG_STATE.

```
BOOL AFXAPI AfxEnableMemoryLeakDump(BOOL bDump);
```

### <a name="parameters"></a>parâmetros

*bDump*<br/>
no VERDADEIRO indica que o despejo de vazamento de memória está habilitado; FALSO indica que o despejo de vazamento de memória está desabilitado.

### <a name="return-value"></a>Valor Retornado

O valor anterior desse sinalizador.

### <a name="remarks"></a>Comentários

Quando um aplicativo descarrega a biblioteca do MFC, a biblioteca do MFC verifica se há vazamentos de memória. Neste ponto, quaisquer vazamentos de memória são relatados ao usuário por meio da janela de **depuração** do Visual Studio.

Se seu aplicativo carregar outra biblioteca antes da biblioteca do MFC, algumas alocações de memória nessa biblioteca serão incorretamente relatadas como vazamentos de memória. Falsos vazamentos de memória podem fazer com que seu aplicativo se feche lentamente, pois a biblioteca do MFC os relata. Nesse caso, use `AfxEnableMemoryLeakDump` para desabilitar o despejo de perda de memória.

> [!NOTE]
> Se você usar esse método para desativar o despejo de vazamento de memória, não receberá relatórios de vazamentos de memória válidos em seu aplicativo. Você só deve usar esse método se tiver certeza de que o relatório de vazamento de memória contém vazamentos de memória falso.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxenablememorytracking"></a><a name="afxenablememorytracking"></a> AfxEnableMemoryTracking

O rastreamento de memória de diagnóstico normalmente é habilitado na versão de depuração do MFC.

```
BOOL AfxEnableMemoryTracking(BOOL bTrack);
```

### <a name="parameters"></a>parâmetros

*bTrack*<br/>
Definir esse valor como TRUE ativa o controle de memória; FALSE desativa-o.

### <a name="return-value"></a>Valor Retornado

A configuração anterior do sinalizador de habilitação de rastreamento.

### <a name="remarks"></a>Comentários

Use essa função para desabilitar o rastreamento em seções do seu código que você sabe que estão alocando blocos corretamente.

Para obter mais informações sobre o `AfxEnableMemoryTracking` , consulte [Debugging MFC Applications](/visualstudio/debugger/mfc-debugging-techniques).

> [!NOTE]
> Essa função funciona apenas na versão de depuração do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#24](../../mfc/codesnippet/cpp/diagnostic-services_12.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxismemoryblock"></a><a name="afxismemoryblock"></a> AfxIsMemoryBlock

Testa um endereço de memória para se certificar de que ele representa um bloco de memória atualmente ativo que foi alocado pela versão de diagnóstico do **`new`** .

```
BOOL AfxIsMemoryBlock(
    const void* p,
    UINT nBytes,
    LONG* plRequestNumber = NULL);
```

### <a name="parameters"></a>parâmetros

*DTI*<br/>
Aponta para o bloco de memória a ser testado.

*nBytes*<br/>
Contém o comprimento do bloco de memória em bytes.

*plRequestNumber*<br/>
Aponta para um **`long`** número inteiro que será preenchido com o número de sequência de alocação do bloco de memória, ou zero se não representar um bloco de memória ativo no momento.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o bloco de memória estiver alocado no momento e o comprimento estiver correto; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ele também verifica o tamanho especificado em relação ao tamanho alocado original. Se a função retornar zero, o número de sequência de alocação será retornado em *plRequestNumber*. Esse número representa a ordem na qual o bloco foi alocado em relação a todas as outras **`new`** alocações.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#27](../../mfc/codesnippet/cpp/diagnostic-services_13.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxisvalidaddress"></a><a name="afxisvalidaddress"></a> AfxIsValidAddress

Testa qualquer endereço de memória para garantir que ele esteja totalmente contido no espaço de memória do programa.

```
BOOL AfxIsValidAddress(
    const void* lp,
    UINT nBytes,
    BOOL bReadWrite = TRUE);
```

### <a name="parameters"></a>parâmetros

*LP*<br/>
Aponta para o endereço de memória a ser testado.

*nBytes*<br/>
Contém o número de bytes de memória a serem testados.

*bReadWrite*<br/>
Especifica se a memória é para leitura e gravação (TRUE) ou apenas leitura (FALSE).

### <a name="return-value"></a>Valor Retornado

Em compilações de depuração, é diferente de zero se o bloco de memória especificado estiver inteiramente contido dentro do espaço de memória do programa; caso contrário, 0.

Em compilações não depuradas, é diferente de zero se *LP* não for NULL; caso contrário, 0.

### <a name="remarks"></a>Comentários

O endereço não está restrito a blocos alocados pelo **`new`** .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#28](../../mfc/codesnippet/cpp/diagnostic-services_14.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxisvalidstring"></a><a name="afxisvalidstring"></a> AfxIsValidString

Use essa função para determinar se um ponteiro para uma cadeia de caracteres é válido.

```
BOOL  AfxIsValidString(
    LPCSTR lpsz,
    int nLength = -1);
```

### <a name="parameters"></a>parâmetros

*lpsz*<br/>
O ponteiro a ser testado.

*nLength*<br/>
Especifica o comprimento da cadeia de caracteres a ser testada, em bytes. Um valor de-1 indica que a cadeia de caracteres será terminada em nulo.

### <a name="return-value"></a>Valor Retornado

Em compilações de depuração, diferente de zero se o ponteiro especificado aponta para uma cadeia de caracteres do tamanho especificado; caso contrário, 0.

Em compilações não depuradas, diferente de zero se *lpsz* não for nulo; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#29](../../mfc/codesnippet/cpp/diagnostic-services_15.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxsetallochook"></a><a name="afxsetallochook"></a> AfxSetAllocHook

Define um gancho que habilita a chamada da função especificada antes de cada bloco de memória ser alocado.

```
AFX_ALLOC_HOOK AfxSetAllocHook(AFX_ALLOC_HOOK pfnAllocHook);
```

### <a name="parameters"></a>parâmetros

*pfnAllocHook*<br/>
Especifica o nome da função a ser chamada. Consulte os comentários para o protótipo de uma função de alocação.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se você quiser permitir a alocação; caso contrário, 0.

### <a name="remarks"></a>Comentários

O biblioteca MFC o alocador de memória de depuração pode chamar uma função de gancho definida pelo usuário para permitir que o usuário monitore uma alocação de memória e controle se a alocação é permitida. As funções de gancho de alocação são protótipos da seguinte maneira:

**Bool AFXAPI AllocHook (size_t** `nSize` **, bool** `bObject` **, Long** `lRequestNumber` **);**

*nSize*<br/>
O tamanho da alocação de memória proposta.

*bObject*<br/>
TRUE se a alocação for para um `CObject` objeto derivado; caso contrário, false.

*lRequestNumber*<br/>
O número de sequência da alocação de memória.

Observe que a Convenção de chamada AFXAPI implica que o receptor deve remover os parâmetros da pilha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxdoforallclasses"></a><a name="afxdoforallclasses"></a> AfxDoForAllClasses

Chama a função de iteração especificada para todas as `CObject` classes derivadas de Serializable no espaço de memória do aplicativo.

```cpp
void
AFXAPI AfxDoForAllClasses(
    void (* pfn)(const CRuntimeClass* pClass, void* pContext),
    void* pContext);
```

### <a name="parameters"></a>parâmetros

*PFN*<br/>
Aponta para uma função de iteração a ser chamada para cada classe. Os argumentos de função são um ponteiro para um `CRuntimeClass` objeto e um ponteiro void para dados adicionais que o chamador fornece para a função.

*pContext*<br/>
Aponta para dados opcionais que o chamador pode fornecer à função de iteração. Esse ponteiro pode ser nulo.

### <a name="remarks"></a>Comentários

`CObject`As classes derivadas de Serializable são classes derivadas usando a macro DECLARE_SERIAL. O ponteiro passado para `AfxDoForAllClasses` em *pContext* é passado para a função de iteração especificada sempre que é chamado.

> [!NOTE]
> Essa função funciona apenas na versão de depuração do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#113](../../mfc/codesnippet/cpp/diagnostic-services_16.cpp)]

[!code-cpp[NVC_MFCCollections#114](../../mfc/codesnippet/cpp/diagnostic-services_17.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxdoforallobjects"></a><a name="afxdoforallobjects"></a> AfxDoForAllObjects

Executa a função de iteração especificada para todos os objetos derivados de `CObject` que foram alocados com **`new`** .

```cpp
void AfxDoForAllObjects(
    void (* pfn)(CObject* pObject, void* pContext),
    void* pContext);
```

### <a name="parameters"></a>parâmetros

*PFN*<br/>
Aponta para uma função de iteração a ser executada para cada objeto. Os argumentos de função são um ponteiro para um `CObject` e um ponteiro void para dados adicionais que o chamador fornece à função.

*pContext*<br/>
Aponta para dados opcionais que o chamador pode fornecer à função de iteração. Esse ponteiro pode ser nulo.

### <a name="remarks"></a>Comentários

Os objetos Stack, global ou Embedded não são enumerados. O ponteiro passado para `AfxDoForAllObjects` em *pContext* é passado para a função de iteração especificada cada vez que é chamado.

> [!NOTE]
> Essa função funciona apenas na versão de depuração do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#115](../../mfc/codesnippet/cpp/diagnostic-services_18.cpp)]

[!code-cpp[NVC_MFCCollections#116](../../mfc/codesnippet/cpp/diagnostic-services_19.cpp)]

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[CObject::D UMP](cobject-class.md#dump)
