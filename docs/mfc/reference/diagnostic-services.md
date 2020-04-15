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
ms.openlocfilehash: 8db12a73d64641a52fea3056de8ab3180c9239b2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365788"
---
# <a name="diagnostic-services"></a>Serviços de diagnóstico

A Biblioteca de Classes da Microsoft Foundation fornece muitos serviços de diagnóstico que facilitam a depuração de seus programas. Esses serviços de diagnóstico incluem macros e funções globais que permitem rastrear as alocações de memória do programa, despejar o conteúdo dos objetos durante o tempo de execução e imprimir mensagens de depuração durante o tempo de execução. As macros e funções globais dos serviços de diagnóstico são agrupadas nas seguintes categorias:

- Macros de diagnóstico geral

- Funções e variáveis de diagnóstico geral

- Funções de diagnóstico de objeto

Essas macros e funções estão disponíveis `CObject` para todas as classes derivadas das versões Debug e Release do MFC. No entanto, todos, exceto DEBUG_NEW e VERIFY não fazem nada na versão Release.

Na biblioteca Debug, todos os blocos de memória alocados são entrelaçados com uma série de "bytes de guarda". Se esses bytes são perturbados por uma gravação de memória errante, então as rotinas de diagnóstico podem relatar um problema. Se você incluir a linha:

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/diagnostic-services_1.cpp)]

em seu arquivo de implementação, todas as chamadas para **novo** armazenarão o nome do arquivo e o número de linha onde a alocação de memória ocorreu. A função [CMemoryState::DumpAllObjectsSince](cmemorystate-structure.md#dumpallobjectssince) exibirá essas informações extras, permitindo identificar vazamentos de memória. Consulte também a classe [CDumpContext](../../mfc/reference/cdumpcontext-class.md) para obter informações adicionais sobre a saída de diagnóstico.

Além disso, a biblioteca de tempo de execução C também suporta um conjunto de funções de diagnóstico que você pode usar para depurar seus aplicativos. Para obter mais informações, consulte [Debug Routines](../../c-runtime-library/debug-routines.md) na referência da biblioteca em tempo de execução.

### <a name="mfc-general-diagnostic-macros"></a>Macros de diagnóstico geral do MFC

|||
|-|-|
|[Assert](#assert)|Imprime uma mensagem e, em seguida, aborta o programa se a expressão especificada for avaliada como FALSA na versão Depuração da biblioteca.|
|[ASSERT_KINDOF](#assert_kindof)|Testa que um objeto é um objeto da classe especificada ou de uma classe derivada da classe especificada.|
|[ASSERT_VALID](#assert_valid)|Testa a validade interna de `AssertValid` um objeto chamando sua função de membro; tipicamente substituído de `CObject`.|
|[DEBUG_NEW](#debug_new)|Fornece um nome de arquivo e um número de linha para todas as alocações de objeto no modo Debug para ajudar a encontrar vazamentos de memória.|
|[DEBUG_ONLY](#debug_only)|Semelhante ao ASSERT, mas não testa o valor da expressão; útil para código que deve ser executado apenas no modo Debug.|
|[GARANTA e ENSURE_VALID](#ensure)|Use para validar a correção dos dados.|
|[THIS_FILE](#this_file)|Expande-se para o nome do arquivo que está sendo compilado.|
|[Rastreamento](#trace)|Fornece `printf`capacidade semelhante à versão Debug da biblioteca.|
|[Verificar](#verify)|Semelhante ao ASSERT, mas avalia a expressão na versão Release da biblioteca, bem como na versão Debug.|

### <a name="mfc-general-diagnostic-variables-and-functions"></a>MFC General Diagnostic Variables and Functions

|||
|-|-|
|[Afxdump](#afxdump)|Variável global que envia informações [do CDumpContext](../../mfc/reference/cdumpcontext-class.md) para a janela de saída do depurador ou para o terminal de depuração.|
|[afxMemDF](#afxmemdf)|Variável global que controla o comportamento do alocador de memória depuração.|
|[AfxCheckError](#afxcheckerror)|Variável global usada para testar o SCODE aprovado para ver se é um erro e, se for o caso, lança o erro apropriado.|
|[AfxCheckMemory](#afxcheckmemory)|Verifica a integridade de toda a memória atualmente alocada.|
|[AfxDebugBreak](#afxdebugbreak)|Causa uma quebra na execução.|
|[AfxDump](#cdumpcontext_in_mfc)|Se for chamado durante o depurador, despeje o estado de um objeto durante a depuração.|
|[AfxDump](#afxdump)|Função interna que despeja o estado de um objeto durante a depuração.|
|[AfxDumpStack](#afxdumpstack)|Gerar uma imagem da pilha atual. Esta função está sempre ligada estáticamente.|
|[AfxEnableMemoryLeakDump](#afxenablememoryleakdump)|Permite o despejo de vazamento de memória.|
|[AfxEnableMemoryTracking](#afxenablememorytracking)|Liga e desliga o rastreamento de memória.|
|[AfxIsMemoryBlock](#afxismemoryblock)|Verifica se um bloco de memória foi alocado corretamente.|
|[AfxIsValidAddress](#afxisvalidaddress)|Verifica se um intervalo de endereço de memória está dentro dos limites do programa.|
|[AfxIsValidString](#afxisvalidstring)|Determina se um ponteiro para uma seqüência é válido.|
|[AfxSetAllocHook](#afxsetallochook)|Habilita a chamada de uma função em cada alocação de memória.|

### <a name="mfc-object-diagnostic-functions"></a>Funções de diagnóstico de objeto smfc

|||
|-|-|
|[AfxDoForAllClasses](#afxdoforallclasses)|Executa uma função `CObject`especificada em todas as classes derivadas que suportam verificação de tipo de tempo de execução.|
|[AfxDoForAllObjects](#afxdoforallobjects)|Executa uma função `CObject`especificada em todos os objetos derivados que foram alocados com **novo**.|

### <a name="mfc-compilation-macros"></a>Macros de compilação do MFC

|||
|-|-|
|[_AFX_SECURE_NO_WARNINGS](#afx_secure_no_warnings)|Suprime avisos de compilador para o uso de funções MFC depreciadas.|

## <a name="_afx_secure_no_warnings"></a><a name="afx_secure_no_warnings"></a>_AFX_SECURE_NO_WARNINGS

Suprime avisos de compilador para o uso de funções MFC depreciadas.

### <a name="syntax"></a>Sintaxe

```
_AFX_SECURE_NO_WARNINGS
```

### <a name="example"></a>Exemplo

Esta amostra de código causaria um aviso de compilador se _AFX_SECURE_NO_WARNINGS não fossem definidas.

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

## <a name="afxdebugbreak"></a><a name="afxdebugbreak"></a>Afxdebugbreak

Chame esta função para causar uma pausa (no local da chamada para `AfxDebugBreak`) na execução da versão de depuração do seu aplicativo MFC.

### <a name="syntax"></a>Sintaxe

```
void AfxDebugBreak( );
```

### <a name="remarks"></a>Comentários

`AfxDebugBreak`não tem efeito nas versões de versão de um aplicativo MFC e deve ser removido. Esta função só deve ser usada em aplicações MFC. Use a versão `DebugBreak`da API Win32 para causar uma quebra em aplicativos não-MFC.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxver_.h

## <a name="assert"></a><a name="assert"></a>Assert

Avalia seu argumento.

```
ASSERT(booleanExpression)
```

### <a name="parameters"></a>Parâmetros

*Booleanexpression*<br/>
Especifica uma expressão (incluindo valores de ponteiro) que avalia como não zero ou 0.

### <a name="remarks"></a>Comentários

Se o resultado for 0, a macro imprime uma mensagem de diagnóstico e aborta o programa. Se a condição não é zero, não faz nada.

A mensagem de diagnóstico tem o formato

`assertion failed in file <name> in line <num>`

onde *o nome* é o nome do arquivo de origem, e *num* é o número de linha da afirmação que falhou no arquivo de origem.

Na versão de versão do MFC, a ASSERT não avalia a expressão e, portanto, não interrompe o programa. Se a expressão deve ser avaliada independentemente do ambiente, use a macro VERIFY no lugar de ASSERT.

> [!NOTE]
> Esta função está disponível apenas na versão Debug do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#44](../../mfc/codesnippet/cpp/diagnostic-services_2.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="assert_kindof"></a><a name="assert_kindof"></a>ASSERT_KINDOF

Esta macro afirma que o objeto apontado é um objeto da classe especificada, ou é um objeto de uma classe derivada da classe especificada.

```
ASSERT_KINDOF(classname, pobject)
```

### <a name="parameters"></a>Parâmetros

*Classname*<br/>
O nome `CObject`de uma classe derivada.

*Pobject*<br/>
Um ponteiro para um objeto de classe.

### <a name="remarks"></a>Comentários

O parâmetro *pobject* deve ser um ponteiro para um objeto e pode ser **const**. O objeto apontado para e `CObject` a classe deve suportar informações de classe em tempo de execução. Como exemplo, para `pDocument` garantir que é um `CMyDoc` ponteiro para um objeto da classe, ou qualquer um de seus derivados, você poderia codificar:

[!code-cpp[NVC_MFCDocView#194](../../mfc/codesnippet/cpp/diagnostic-services_3.cpp)]

Usar `ASSERT_KINDOF` a macro é exatamente o mesmo que codificação:

[!code-cpp[NVC_MFCDocView#195](../../mfc/codesnippet/cpp/diagnostic-services_4.cpp)]

Essa função funciona apenas para classes declaradas com a [DECLARE_DYNAMIC](run-time-object-model-services.md#declare_dynamic ou [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) macro.

> [!NOTE]
> Esta função está disponível apenas na versão Debug do MFC.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="assert_valid"></a><a name="assert_valid"></a>Assert_valid

Use para testar suas suposições sobre a validade do estado interno de um objeto.

```
ASSERT_VALID(pObject)
```

### <a name="parameters"></a>Parâmetros

*Pobject*<br/>
Especifica um objeto de uma `CObject` classe derivada de que `AssertValid` tem uma versão sobreposta da função membro.

### <a name="remarks"></a>Comentários

ASSERT_VALID chama `AssertValid` a função membro do objeto passou como seu argumento.

Na versão de lançamento do MFC, ASSERT_VALID não faz nada. Na versão Debug, ele valida o ponteiro, verifica contra NULL `AssertValid` e chama as funções do próprio membro do objeto. Se algum desses testes falhar, uma mensagem de alerta será exibida da mesma forma [que ASSERT](#assert).

> [!NOTE]
> Esta função está disponível apenas na versão Debug do MFC.

Para obter mais informações e exemplos, consulte [Depuração de aplicativos MFC](/visualstudio/debugger/mfc-debugging-techniques).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#19](../../mfc/codesnippet/cpp/diagnostic-services_5.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="debug_new"></a><a name="debug_new"></a>Debug_new

Ajuda a encontrar vazamentos de memória.

```
#define  new DEBUG_NEW
```

### <a name="remarks"></a>Comentários

Você pode usar DEBUG_NEW em todos os lugares do seu programa que normalmente usaria o **novo** operador para alocar o armazenamento de pilhas.

No modo de depuração (quando o símbolo **de _DEBUG** é definido), DEBUG_NEW mantém o controle do nome do arquivo e do número da linha para cada objeto que ele aloca. Em seguida, quando você usa a [função CMemoryState::DumpAllObjectsSince](cmemorystate-structure.md#dumpallobjectssince) member, cada objeto alocado com DEBUG_NEW é mostrado com o nome do arquivo e o número da linha onde foi alocado.

Para usar DEBUG_NEW, insira a seguinte diretiva em seus arquivos de origem:

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/diagnostic-services_1.cpp)]

Depois de inserir esta diretiva, o pré-processador inserirá DEBUG_NEW onde você usar **novo,** e o MFC faz o resto. Quando você compila uma versão de versão do seu programa, DEBUG_NEW resolve uma **nova** operação simples e as informações do nome do arquivo e do número da linha não são geradas.

> [!NOTE]
> Nas versões anteriores do MFC (4.1 `#define` e anteriores) você precisava colocar a declaração depois de todas as declarações que chamavam de IMPLEMENT_DYNCREATE ou IMPLEMENT_SERIAL macros. Isso não é mais necessário.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="debug_only"></a><a name="debug_only"></a>DEBUG_ONLY

No modo de depuração (quando o símbolo **_DEBUG** é definido), DEBUG_ONLY avalia seu argumento.

```
DEBUG_ONLY(expression)
```

### <a name="remarks"></a>Comentários

Em uma compilação de lançamento, DEBUG_ONLY não avalia seu argumento. Isso é útil quando você tem um código que deve ser executado apenas em compilações de depuração.

A DEBUG_ONLY macro é equivalente `#ifdef _DEBUG` `#endif`à *expressão* circundante com e .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#32](../../mfc/codesnippet/cpp/diagnostic-services_6.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

### <a name="ensure-and-ensure_valid"></a><a name="ensure"></a>GARANTA e ENSURE_VALID

Use para validar a correção dos dados.

### <a name="syntax"></a>Sintaxe

```
ENSURE(  booleanExpression )
ENSURE_VALID( booleanExpression  )
```

### <a name="parameters"></a>Parâmetros

*Booleanexpression*<br/>
Especifica uma expressão booleana a ser testada.

### <a name="remarks"></a>Comentários

O objetivo dessas macros é melhorar a validação dos parâmetros. As macros impedem o processamento adicional de parâmetros incorretos em seu código. Ao contrário das macros ASSERT, as macros ENSURE lançam uma exceção, além de gerar uma afirmação.

As macros se comportam de duas maneiras, de acordo com a configuração do projeto. As macros chamam ASSERT e, em seguida, lançam uma exceção se a afirmação falhar. Assim, nas configurações de Depuração (ou seja, onde _DEBUG é definida) as macros produzem uma afirmação e exceção enquanto nas configurações de Release, as macros produzem apenas a exceção (assert não avalia a expressão nas configurações de Release).

O macro ENSURE_ARG age como a macro ENSURE.

ENSURE_VALID chama a ASSERT_VALID macro (que tem um efeito apenas em compilações de depuração). Além disso, ENSURE_VALID abre uma exceção se o ponteiro for NULO. O teste NULL é realizado nas configurações Debug e Release.

Se algum desses testes falhar, uma mensagem de alerta será exibida da mesma forma que a ASSERT. A macro lança uma exceção de argumento inválida, se necessário.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="this_file"></a><a name="this_file"></a>THIS_FILE

Expande-se para o nome do arquivo que está sendo compilado.

### <a name="syntax"></a>Sintaxe

```
THIS_FILE
```

### <a name="remarks"></a>Comentários

As informações são utilizadas pelas macros ASSERT e VERIFY. O Assistente de Aplicativo e os assistentes de código colocam a macro nos arquivos de código-fonte que eles criam.

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

**Cabeçalho:** afx.h

## <a name="trace"></a><a name="trace"></a>Rastreamento

Envia a seqüência especificada para o depurador do aplicativo atual.

```
TRACE(exp)
TRACE(DWORD  category,  UINT  level, LPCSTR lpszFormat, ...)
```

### <a name="remarks"></a>Comentários

Consulte [ATLTRACE2](../../atl/reference/debugging-and-error-reporting-macros.md#atltrace2) para obter uma descrição do TRACE. Trace e ATLTRACE2 têm o mesmo comportamento.

Na versão de depuração do MFC, essa macro envia a seqüência especificada para o depurador do aplicativo atual. Em uma compilação de versão, essa macro não compila para nada (nenhum código é gerado).

Para obter mais informações, consulte [Depuração de aplicativos MFC](/visualstudio/debugger/mfc-debugging-techniques).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="verify"></a><a name="verify"></a>Verificar

Na versão Debug do MFC, avalia seu argumento.

```
VERIFY(booleanExpression)
```

### <a name="parameters"></a>Parâmetros

*Booleanexpression*<br/>
Especifica uma expressão (incluindo valores de ponteiro) que avalia como não zero ou 0.

### <a name="remarks"></a>Comentários

Se o resultado for 0, a macro imprime uma mensagem de diagnóstico e interrompe o programa. Se a condição não é zero, não faz nada.

A mensagem de diagnóstico tem o formato

`assertion failed in file <name> in line <num>`

onde *o nome* é o nome do arquivo de origem e *num* é o número de linha da afirmação que falhou no arquivo de origem.

Na versão de versão do MFC, o VERIFY avalia a expressão, mas não imprime ou interrompe o programa. Por exemplo, se a expressão for uma chamada de função, a chamada será feita.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#198](../../mfc/codesnippet/cpp/diagnostic-services_7.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxdump-cdumpcontext-in-mfc"></a><a name="cdumpcontext_in_mfc"></a>afxDump (CDumpContext em MFC)

Fornece capacidade básica de dumping de objetos em sua aplicação.

```
CDumpContext  afxDump;
```

### <a name="remarks"></a>Comentários

`afxDump`é um objeto [CDumpContext](../../mfc/reference/cdumpcontext-class.md) predefinido `CDumpContext` que permite enviar informações para a janela de saída do depurador ou para um terminal de depuração. Normalmente, você `afxDump` fornece como `CObject::Dump`parâmetro para .

No Windows NT e em `afxDump` todas as versões do Windows, a saída é enviada para a janela Output-Debug do Visual C++ quando você depura seu aplicativo.

Esta variável é definida apenas na versão Debug do MFC. Para obter `afxDump`mais informações sobre , consulte [Depuração de aplicativos MFC](/visualstudio/debugger/mfc-debugging-techniques).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#23](../../mfc/codesnippet/cpp/diagnostic-services_8.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxdump-internal"></a><a name="afxdump"></a>AfxDump (Interno)

Função interna que o MFC usa para despejar o estado de um objeto durante a depuração.

### <a name="syntax"></a>Sintaxe

```
void AfxDump(const CObject* pOb);
```

### <a name="parameters"></a>Parâmetros

*pOb*<br/>
Um ponteiro para um objeto de `CObject`uma classe derivada de .

### <a name="remarks"></a>Comentários

`AfxDump`chama a função `Dump` de membro de um objeto e `afxDump` envia as informações para o local especificado pela variável. `AfxDump`está disponível apenas na versão Debug do MFC.

O código do `AfxDump`programa não deve `Dump` chamar, mas deve chamar a função membro do objeto apropriado.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxmemdf"></a><a name="afxmemdf"></a>Afxmemdf

Esta variável é acessível a partir de um depurador ou do seu programa e permite que você ajuste diagnósticos de alocação.

```
int  afxMemDF;
```

### <a name="remarks"></a>Comentários

`afxMemDF`pode ter os seguintes valores especificados pela enumeração: `afxMemDF`

- `allocMemDF`Ativa o alocador de depuração (configuração padrão na biblioteca Debug).

- `delayFreeMemDF`Atrasa a liberação da memória. Enquanto seu programa libera um bloco de memória, o alocador não retorna essa memória ao sistema operacional subjacente. Isso colocará o máximo de estresse de memória em seu programa.

- `checkAlwaysMemDF`Chamadas `AfxCheckMemory` toda vez que a memória é alocada ou liberada. Isso reduzirá significativamente as alocações e desalocações de memória.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#30](../../mfc/codesnippet/cpp/diagnostic-services_9.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxcheckerror"></a><a name="afxcheckerror"></a>AfxCheckError

Esta função testa o SCODE aprovado para ver se é um erro.

```
void AFXAPI AfxCheckError(SCODE sc);
throw CMemoryException*
throw COleException*
```

### <a name="remarks"></a>Comentários

Se for um erro, a função abre uma exceção. Se o SCODE aprovado for E_OUTOFMEMORY, a função será lançada em uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) chamando [AfxThrowMemoryException](exception-processing.md#afxthrowmemoryexception). Caso contrário, a função lança uma [COleException](../../mfc/reference/coleexception-class.md) chamando [AfxThrowOleException](exception-processing.md#afxthrowoleexception).

Esta função pode ser usada para verificar os valores de retorno das chamadas para funções OLE em sua aplicação. Ao testar o valor de retorno com esta função em seu aplicativo, você pode reagir adequadamente às condições de erro com uma quantidade mínima de código.

> [!NOTE]
> Esta função tem o mesmo efeito em compilações de depuração e não-depuração.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#33](../../mfc/codesnippet/cpp/diagnostic-services_10.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxcheckmemory"></a><a name="afxcheckmemory"></a>Afxcheckmemory

Esta função valida o pool de memória livre e imprime mensagens de erro conforme necessário.

```
BOOL  AfxCheckMemory();
```

### <a name="return-value"></a>Valor retornado

Não zero se não houver erros de memória; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se a função não detectar nenhuma corrupção de memória, ela não imprime nada.

Todos os blocos de memória atualmente alocados no heap são verificados, incluindo aqueles alocados por **novos,** mas não aqueles alocados por chamadas diretas para alocadores de memória subjacentes, como a função **malloc** ou a `GlobalAlloc` função Windows. Se algum bloco for encontrado corrompido, uma mensagem será impressa na saída do depurador.

Se você incluir a linha

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/diagnostic-services_1.cpp)]

em um módulo de programa, em seguida, chamadas subseqüentes para `AfxCheckMemory` mostrar o nome de arquivo e o número de linha onde a memória foi alocada.

> [!NOTE]
> Se o seu módulo contiver uma ou mais implementações `#define` de classes serializáveis, então você deve colocar a linha após a última chamada de macro IMPLEMENT_SERIAL.

Esta função funciona apenas na versão Debug do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#26](../../mfc/codesnippet/cpp/diagnostic-services_11.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxdump-mfc"></a><a name="afxdump"></a>AfxDump (MFC)

Chame esta função enquanto estiver no depurador para despejar o estado de um objeto durante a depuração.

```
void AfxDump(const CObject* pOb);
```

### <a name="parameters"></a>Parâmetros

*pOb*<br/>
Um ponteiro para um objeto de `CObject`uma classe derivada de .

### <a name="remarks"></a>Comentários

`AfxDump`chama a função `Dump` de membro de um objeto e `afxDump` envia as informações para o local especificado pela variável. `AfxDump`está disponível apenas na versão Debug do MFC.

O código do `AfxDump`programa não deve `Dump` chamar, mas deve chamar a função membro do objeto apropriado.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxdumpstack"></a><a name="afxdumpstack"></a>Afxdumpstack

Esta função global pode ser usada para gerar uma imagem da pilha atual.

```
void AFXAPI AfxDumpStack(DWORD dwTarget = AFX_STACK_DUMP_TARGET_DEFAULT);
```

### <a name="parameters"></a>Parâmetros

*dwTarget*<br/>
Indica o alvo da saída de despejo. Os valores possíveis, que podem ser combinados usando o operador bitwise-OR **(&#124;), **são os seguintes:

- AFX_STACK_DUMP_TARGET_TRACE Envia saída por meio da macro [TRACE.](#trace) A macro TRACE gera saída apenas em compilações de depuração; ele não gera saída em compilações de liberação. Além disso, o TRACE pode ser redirecionado para outros alvos além do depurador.

- AFX_STACK_DUMP_TARGET_DEFAULT Envia saída de despejo para o alvo padrão. Para uma compilação de depuração, a saída vai para a macro TRACE. Em uma compilação de versão, a saída vai para a Área de Transferência.

- AFX_STACK_DUMP_TARGET_CLIPBOARD Envia saída apenas para a Área de Transferência. Os dados são colocados na área de transferência como texto simples usando o formato CF_TEXT Área de Transferência.

- AFX_STACK_DUMP_TARGET_BOTH Envia saída para a Área de Transferência e para a macro TRACE, simultaneamente.

- AFX_STACK_DUMP_TARGET_ODS Envia saída diretamente para o depurador por `OutputDebugString()`meio da função Win32 . Essa opção gerará saída de depurador tanto em compilações de depuração quanto de liberação quando um depurador estiver conectado ao processo. AFX_STACK_DUMP_TARGET_ODS sempre atinge o depurador (se estiver conectado) e não pode ser redirecionado.

### <a name="remarks"></a>Comentários

O exemplo abaixo reflete uma única linha `AfxDumpStack` da saída gerada a partir de uma chamada de um manipulador de botões em um aplicativo de diálogo MFC:

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

Cada linha na saída acima indica o endereço da última chamada de função, o nome completo do caminho do módulo que contém a chamada de função e o protótipo de função chamado. Se a chamada de função na pilha não acontecer no endereço exato da função, um deslocamento de bytes será mostrado.

Por exemplo, a tabela a seguir descreve a primeira linha da saída acima:

|Saída|Descrição|
|------------|-----------------|
|`00427D55:`|O endereço de retorno da última chamada de função.|
|`DUMP2\DEBUG\DUMP2.EXE!`|O nome completo do caminho do módulo que contém a chamada de função.|
|`void AfxDumpStack(unsigned long)`|O protótipo de função chamado.|
|`+ 181 bytes`|O deslocamento em bytes do endereço do protótipo `void AfxDumpStack(unsigned long)`da função (neste caso) `00427D55`para o endereço de retorno (neste caso, ).|

`AfxDumpStack`está disponível nas versões de depuração e não depuração das bibliotecas MFC; no entanto, a função está sempre ligada estáticamente, mesmo quando seu arquivo executável usa MFC em um DLL compartilhado. Em implementações de biblioteca compartilhada, a função é encontrada no MFCS42. Biblioteca LIB (e suas variantes).

Para usar esta função com sucesso:

- O arquivo IMAGEHLP. DLL deve estar no seu caminho. Se você não tiver essa DLL, a função exibirá uma mensagem de erro. Consulte [Image Help Library](/windows/win32/Debug/image-help-library) para obter informações sobre o conjunto de funções fornecido pelo IMAGEHLP.

- Os módulos que possuem quadros na pilha devem incluir informações de depuração. Se eles não contiverem informações de depuração, a função ainda gerará um traço de pilha, mas o rastreamento será menos detalhado.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxenablememoryleakdump"></a><a name="afxenablememoryleakdump"></a>AfxEnableMemoryLeakDump

Ativa e desativa o despejo de vazamento de memória no AFX_DEBUG_STATE destruidor.

```
BOOL AFXAPI AfxEnableMemoryLeakDump(BOOL bDump);
```

### <a name="parameters"></a>Parâmetros

*bDump*<br/>
[em] TRUE indica que o despejo de vazamento de memória está ativado; FALSE indica que o despejo de vazamento de memória está desativado.

### <a name="return-value"></a>Valor retornado

O valor anterior para esta bandeira.

### <a name="remarks"></a>Comentários

Quando um aplicativo descarrega a biblioteca MFC, a biblioteca Do MFC verifica se há vazamentos de memória. Neste ponto, quaisquer vazamentos de memória são relatados ao usuário através da janela **Debug** do Visual Studio.

Se o aplicativo carregar outra biblioteca antes da biblioteca Do MFC, algumas alocações de memória nessa biblioteca serão incorretamente relatadas como vazamentos de memória. Vazamentos de memória falsos podem fazer com que seu aplicativo feche lentamente à medida que a biblioteca do MFC os relata. Neste caso, `AfxEnableMemoryLeakDump` use para desativar o despejo de vazamento de memória.

> [!NOTE]
> Se você usar este método para desativar o dump de vazamento de memória, você não receberá relatórios de vazamentos de memória válidos em seu aplicativo. Você só deve usar este método se estiver confiante de que o relatório de vazamento de memória contém falsos vazamentos de memória.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxenablememorytracking"></a><a name="afxenablememorytracking"></a>AfxEnableMemoryTracking

O rastreamento de memória diagnóstica é normalmente ativado na versão Debug do MFC.

```
BOOL AfxEnableMemoryTracking(BOOL bTrack);
```

### <a name="parameters"></a>Parâmetros

*bTrack*<br/>
Definir esse valor como TRUE ativa o rastreamento de memória; FALSE desliga.

### <a name="return-value"></a>Valor retornado

A configuração anterior do sinalizador de habilitação de rastreamento.

### <a name="remarks"></a>Comentários

Use esta função para desativar o rastreamento em seções do seu código que você sabe que estão alocando blocos corretamente.

Para obter `AfxEnableMemoryTracking`mais informações sobre , consulte [Depuração de aplicativos MFC](/visualstudio/debugger/mfc-debugging-techniques).

> [!NOTE]
> Esta função funciona apenas na versão Debug do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#24](../../mfc/codesnippet/cpp/diagnostic-services_12.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxismemoryblock"></a><a name="afxismemoryblock"></a>AfxIsMemoryBlock

Testa um endereço de memória para ter certeza de que ele representa um bloco de memória ativo atualmente que foi alocado pela versão diagnóstica do **novo**.

```
BOOL AfxIsMemoryBlock(
    const void* p,
    UINT nBytes,
    LONG* plRequestNumber = NULL);
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Aponta para o bloco de memória a ser testado.

*Nbytes*<br/>
Contém o comprimento do bloco de memória em bytes.

*plRequestNumber*<br/>
Aponta para um **inteiro longo** que será preenchido com o número da seqüência de alocação do bloco de memória ou zero se ele não representar um bloco de memória ativo no momento.

### <a name="return-value"></a>Valor retornado

Não zero se o bloco de memória estiver atualmente alocado e o comprimento estiver correto; caso contrário, 0.

### <a name="remarks"></a>Comentários

Também verifica o tamanho especificado em relação ao tamanho original alocado. Se a função retornar não zero, o número da seqüência de alocação será retornado em *plRequestNumber*. Esse número representa a ordem em que o bloco foi alocado em relação a todas as outras **novas** alocações.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#27](../../mfc/codesnippet/cpp/diagnostic-services_13.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxisvalidaddress"></a><a name="afxisvalidaddress"></a>Endereço AfxIsValid

Testa qualquer endereço de memória para garantir que ele esteja totalmente contido no espaço de memória do programa.

```
BOOL AfxIsValidAddress(
    const void* lp,
    UINT nBytes,
    BOOL bReadWrite = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Lp*<br/>
Aponta para o endereço de memória a ser testado.

*Nbytes*<br/>
Contém o número de bytes de memória a serem testados.

*bReadWrite*<br/>
Especifica se a memória é tanto para leitura quanto para escrita (TRUE) ou apenas para leitura (FALSE).

### <a name="return-value"></a>Valor retornado

Em compilações de depuração, não zero se o bloco de memória especificado estiver contido inteiramente no espaço de memória do programa; caso contrário, 0.

Em construções não-depuradas, não zero se *lp* não for NULA; caso contrário, 0.

### <a name="remarks"></a>Comentários

O endereço não está restrito aos blocos alocados pelo **novo**.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#28](../../mfc/codesnippet/cpp/diagnostic-services_14.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxisvalidstring"></a><a name="afxisvalidstring"></a>AfxIsValidstring

Use esta função para determinar se um ponteiro para uma seqüência é válido.

```
BOOL  AfxIsValidString(
    LPCSTR lpsz,
    int nLength = -1);
```

### <a name="parameters"></a>Parâmetros

*Lpsz*<br/>
O ponteiro para testar.

*Nlength*<br/>
Especifica o comprimento da seqüência a ser testada em bytes. Um valor de -1 indica que a seqüência será anulada.

### <a name="return-value"></a>Valor retornado

Em compilações de depuração, não zero se o ponteiro especificado apontar para uma seqüência do tamanho especificado; caso contrário, 0.

Em construções não-depuradas, não zero se *lpsz* não for NULO; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#29](../../mfc/codesnippet/cpp/diagnostic-services_15.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxsetallochook"></a><a name="afxsetallochook"></a>AfxSetAllocHook

Define um gancho que habilita a chamada da função especificada antes que cada bloco de memória seja alocado.

```
AFX_ALLOC_HOOK AfxSetAllocHook(AFX_ALLOC_HOOK pfnAllocHook);
```

### <a name="parameters"></a>Parâmetros

*pfnAllocHook*<br/>
Especifica o nome da função a ser chamada. Consulte as Observações para o protótipo de uma função de alocação.

### <a name="return-value"></a>Valor retornado

Não zero se você quiser permitir a alocação; caso contrário, 0.

### <a name="remarks"></a>Comentários

O alocador de memória de depuração da Biblioteca de Classe da Microsoft Foundation pode chamar uma função de gancho definida pelo usuário para permitir que o usuário monitore uma alocação de memória e controle se a alocação é permitida. As funções do gancho de alocação são protótipos da seguinte forma:

**BOOL AFXAPI AllocHook (size_t,** `nSize` **BOOL,** `bObject` **LONG);** `lRequestNumber` **);**

*Nsize*<br/>
O tamanho da alocação de memória proposta.

*bObject*<br/>
TRUE se a alocação for para um `CObject`objeto derivado; caso contrário, FALSO.

*lRequestNumber*<br/>
O número de seqüência da alocação de memória.

Observe que a convenção de chamada aFXAPI implica que a callee deve remover os parâmetros da pilha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxdoforallclasses"></a><a name="afxdoforallclasses"></a>AfxdoforallClasses

Chama a função de iteração `CObject`especificada para todas as classes derivadas serializáveis no espaço de memória do aplicativo.

```
void
AFXAPI AfxDoForAllClasses(
    void (* pfn)(const CRuntimeClass* pClass, void* pContext),
    void* pContext);
```

### <a name="parameters"></a>Parâmetros

*pfn*<br/>
Aponta para uma função de iteração a ser chamada para cada aula. Os argumentos de função `CRuntimeClass` são um ponteiro para um objeto e um ponteiro vazio para dados extras que o chamador fornece para a função.

*pContext*<br/>
Aponta para dados opcionais que o chamador pode fornecer para a função de iteração. Este ponteiro pode ser NULO.

### <a name="remarks"></a>Comentários

Classes `CObject`derivadas serializáveis são classes derivadas usando a macro DECLARE_SERIAL. O ponteiro que `AfxDoForAllClasses` é passado para o *pContext* é passado para a função de iteração especificada cada vez que é chamado.

> [!NOTE]
> Esta função funciona apenas na versão Debug do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#113](../../mfc/codesnippet/cpp/diagnostic-services_16.cpp)]

[!code-cpp[NVC_MFCCollections#114](../../mfc/codesnippet/cpp/diagnostic-services_17.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxdoforallobjects"></a><a name="afxdoforallobjects"></a>AfxdoforAllObjects

Executa a função de iteração especificada `CObject` para todos os objetos derivados dos que foram alocados com **novo**.

```
void AfxDoForAllObjects(
    void (* pfn)(CObject* pObject, void* pContext),
    void* pContext);
```

### <a name="parameters"></a>Parâmetros

*pfn*<br/>
Aponta para uma função de iteração para executar para cada objeto. Os argumentos de função `CObject` são um ponteiro para um ponteiro e um ponteiro vazio para dados extras que o chamador fornece para a função.

*pContext*<br/>
Aponta para dados opcionais que o chamador pode fornecer para a função de iteração. Este ponteiro pode ser NULO.

### <a name="remarks"></a>Comentários

Objetos empilhados, globais ou incorporados não são enumerados. O ponteiro `AfxDoForAllObjects` passado para *pContext* é passado para a função de iteração especificada cada vez que é chamado.

> [!NOTE]
> Esta função funciona apenas na versão Debug do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#115](../../mfc/codesnippet/cpp/diagnostic-services_18.cpp)]

[!code-cpp[NVC_MFCCollections#116](../../mfc/codesnippet/cpp/diagnostic-services_19.cpp)]

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[CObject::Dump](cobject-class.md#dump)
