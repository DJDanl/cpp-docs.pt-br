---
title: Serviços de diagnóstico | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dd420544f341159fa4281c4f837fa222d357e1b1
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50068691"
---
# <a name="diagnostic-services"></a>Serviços de diagnóstico

A biblioteca Microsoft Foundation Class fornece vários serviços de diagnóstico que tornam a depuração de seus programas mais fácil. Esses serviços de diagnóstico incluem macros e funções globais que permitem que você controle a memória do seu programa alocações, despejar o conteúdo dos objetos durante o tempo de execução e imprimir as mensagens de depuração durante o tempo de execução. As macros e funções globais para serviços de diagnóstico são agrupadas nas seguintes categorias:

- Macros de diagnóstico gerais

- Variáveis e funções de diagnóstico gerais

- Funções de diagnóstico do objeto

Essas macros e funções estão disponíveis para todas as classes derivadas de `CObject` em versões de depuração e versão do MFC. No entanto, todos exceto DEBUG_NEW e verifique se não fazer nada na versão de lançamento.

Na biblioteca de depuração, todos os blocos de memória alocada estiverem entre colchetes, com uma série de "bytes de proteção". Se esses bytes são interrompidas por uma gravação de memória errônea, as rotinas de diagnóstico podem relatar um problema. Se você incluir a linha:

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/diagnostic-services_1.cpp)]

em seu arquivo de implementação, todas as chamadas para **novo** armazenará o nome de arquivo e número de linha onde ocorreu a alocação de memória. A função [CMemoryState::DumpAllObjectsSince](cmemorystate-structure.md#dumpallobjectssince) exibirá essas informações extras, permitindo que você identificar vazamentos de memória. Consulte também a classe [CDumpContext](../../mfc/reference/cdumpcontext-class.md) para saber mais sobre os resultados de diagnóstico.

Além disso, a biblioteca de tempo de execução C também oferece suporte a um conjunto de funções de diagnóstico, que você pode usar para depurar seus aplicativos. Para obter mais informações, consulte [rotinas de depuração](../../c-runtime-library/debug-routines.md) na referência da biblioteca de tempo de execução.

### <a name="mfc-general-diagnostic-macros"></a>Macros de diagnóstico gerais MFC

|||
|-|-|
|[ASSERT](#assert)|Imprime uma mensagem e, em seguida, anula o programa se a expressão especificada seja avaliada como FALSE na versão de depuração da biblioteca.|
|[ASSERT_KINDOF](#assert_kindof)|Testes de que um objeto é um objeto da classe especificada ou de uma classe derivada da classe especificada.|
|[ASSERT_VALID](#assert_valid)|Testa a validade interna de um objeto chamando seu `AssertValid` função de membro; normalmente substituída de `CObject`.|
|[DEBUG_NEW](#debug_new)|Fornece um nome de arquivo e número de linha para todas as alocações de objeto no modo de depuração para ajudar a localizar vazamentos de memória.|
|[DEBUG_ONLY](#debug_only)|Semelhante a ASSERT, mas não testa o valor da expressão; é útil para o código que deve ser executado somente no modo de depuração.|
|[Certifique-se e ENSURE_VALID](#ensure)|Use para validar a exatidão dos dados.|
|[THIS_FILE](#this_file)|Expande para o nome do arquivo que está sendo compilado.|
|[TRACE](#trace)|Fornece `printf`-como recurso na versão de depuração da biblioteca.|
|[VERIFIQUE SE](#verify)|Semelhante a ASSERT, mas avalia a expressão na versão de lançamento da biblioteca, bem como na versão de depuração.|

### <a name="mfc-general-diagnostic-variables-and-functions"></a>Funções e variáveis de diagnóstico gerais MFC

|||
|-|-|
|[afxDump](#afxdump)|Variável global que envia [CDumpContext](../../mfc/reference/cdumpcontext-class.md) informações na janela de saída do depurador ou para o terminal de depuração.|
|[afxMemDF](#afxmemdf)|Variável global que controla o comportamento do alocador de memória de depuração.|
|[AfxCheckError](#afxcheckerror)|Variável global usado para testar o SCODE passado para ver se ele é um erro e, em caso afirmativo, gera o erro apropriado.|
|[AfxCheckMemory](#afxcheckmemory)|Verifica que a integridade de todos os memória alocada no momento.|
|[AfxDebugBreak](#afxdebugbreak)|Faz com que uma quebra na execução.|
|[afxDump](#cdumpcontext_in_mfc)|Se for chamado no depurador, despejos de memória o estado de um objeto durante a depuração.|
|[afxDump](#afxdump)|Função interna que o estado de um objeto de despejos de memória durante a depuração.|
|[AfxDumpStack](#afxdumpstack)|Gere uma imagem da pilha atual. Essa função é sempre vinculada estaticamente.|
|[AfxEnableMemoryLeakDump](#afxenablememoryleakdump)|Permite que o despejo de vazamento de memória.|
|[AfxEnableMemoryTracking](#afxenablememorytracking)|Ativa o acompanhamento de intermitente da memória.|
|[AfxIsMemoryBlock](#afxismemoryblock)|Verifica que um bloco de memória foi alocado corretamente.|
|[AfxIsValidAddress](#afxisvalidaddress)|Verifica se um intervalo de endereços de memória está dentro dos limites do programa.|
|[AfxIsValidString](#afxisvalidstring)|Determina se um ponteiro para uma cadeia de caracteres é válido.|
|[AfxSetAllocHook](#afxsetallochook)|Permite chamar uma função em cada alocação de memória.|

### <a name="mfc-object-diagnostic-functions"></a>Funções de diagnóstico de objeto do MFC

|||
|-|-|
|[AfxDoForAllClasses](#afxdoforallclasses)|Executa uma função especificada em todos os `CObject`-derivadas de classes que dão suporte à verificação de tipo de tempo de execução.|
|[AfxDoForAllObjects](#afxdoforallobjects)|Executa uma função especificada em todos os `CObject`-objetos alocados com derivados **nova**.|

### <a name="mfc-compilation-macros"></a>Macros de compilação do MFC

|||
|-|-|
|[_AFX_SECURE_NO_WARNINGS](#afx_secure_no_warnings)|Suprime os avisos do compilador para o uso de funções preteridas do MFC.|

## <a name="afx_secure_no_warnings"></a> _AFX_SECURE_NO_WARNINGS

Suprime os avisos do compilador para o uso de funções preteridas do MFC.

### <a name="syntax"></a>Sintaxe

```
_AFX_SECURE_NO_WARNINGS
```

### <a name="example"></a>Exemplo

Este exemplo de código faria com que um aviso do compilador se _AFX_SECURE_NO_WARNINGS não foram definidas.

```cpp
// define this before including any afx files in stdafx.h
#define _AFX_SECURE_NO_WARNINGS
```
```cpp
CRichEditCtrl* pRichEdit = new CRichEditCtrl;
pRichEdit->Create(WS_CHILD|WS_VISIBLE|WS_BORDER|ES_MULTILINE,
   CRect(10,10,100,200), pParentWnd, 1);
char sz[256];
pRichEdit->GetSelText(sz);
```

## <a name="afxdebugbreak"></a> AfxDebugBreak

Chame essa função para fazer com que uma quebra (no local da chamada para `AfxDebugBreak`) na execução da versão de depuração do seu aplicativo do MFC.

### <a name="syntax"></a>Sintaxe

```
void AfxDebugBreak( );
```

### <a name="remarks"></a>Comentários

`AfxDebugBreak` não tem nenhum efeito em versões de lançamento de um aplicativo do MFC e deve ser removida. Essa função só deve ser usada em aplicativos MFC. Use a versão de API do Win32, `DebugBreak`, para fazer com que uma quebra em aplicativos não MFC.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxver_.h

##  <a name="assert"></a>  ASSERT

Avalia seu argumento.

```
ASSERT(booleanExpression)
```

### <a name="parameters"></a>Parâmetros

*booleanExpression*<br/>
Especifica uma expressão (incluindo valores de ponteiro) que é avaliada como diferente de zero ou igual a 0.

### <a name="remarks"></a>Comentários

Se o resultado é 0, a macro imprime uma mensagem de diagnóstico e anula o programa. Se a condição for diferente de zero, ele não fará nada.

A mensagem de diagnóstico tem o formato

`assertion failed in file <name> in line <num>`

em que *nome* é o nome do arquivo de origem, e *num* é o número de linha da asserção que falhou no arquivo de origem.

Na versão de lançamento do MFC, ASSERT não avalia a expressão e, portanto, não interromperá o programa. Se a expressão deve ser avaliada, independentemente do ambiente, use a macro VERIFY em vez de ASSERT.

> [!NOTE]
>  Esta função está disponível somente na versão de depuração do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#44](../../mfc/codesnippet/cpp/diagnostic-services_2.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="assert_kindof"></a>  ASSERT_KINDOF

Essa macro declara que o objeto apontado é um objeto da classe especificada ou é um objeto de uma classe derivada da classe especificada.

```
ASSERT_KINDOF(classname, pobject)
```

### <a name="parameters"></a>Parâmetros

*classname*<br/>
O nome de um `CObject`-classe derivada.

*pobject*<br/>
Um ponteiro para um objeto de classe.

### <a name="remarks"></a>Comentários

O *pobject* deve ser um ponteiro para um objeto de parâmetro e pode ser **const**. O objeto apontado e a classe deve oferecer suporte `CObject` informações de classe de tempo de execução. Por exemplo, para garantir que `pDocument` é um ponteiro para um objeto do `CMyDoc` classe ou qualquer um dos seus derivados, você pode codificar:

[!code-cpp[NVC_MFCDocView#194](../../mfc/codesnippet/cpp/diagnostic-services_3.cpp)]

Usando o `ASSERT_KINDOF` macro é exatamente a mesma codificação:

[!code-cpp[NVC_MFCDocView#195](../../mfc/codesnippet/cpp/diagnostic-services_4.cpp)]

Essa função funciona apenas em classes declaradas com a [DECLARE_DYNAMIC] (run-tempo-objeto-modelo-services.md #declare_dynamic ou [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) macro.

> [!NOTE]
>  Esta função está disponível somente na versão de depuração do MFC.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="assert_valid"></a>  ASSERT_VALID

Use para testar suas suposições sobre a validade do estado interno de um objeto.

```
ASSERT_VALID(pObject)
```

### <a name="parameters"></a>Parâmetros

*pObject*<br/>
Especifica um objeto de uma classe derivada de `CObject` que tem uma versão de substituição do `AssertValid` função de membro.

### <a name="remarks"></a>Comentários

Chamadas ASSERT_VALID a `AssertValid` a função de membro do objeto passado como seu argumento.

Na versão de lançamento do MFC ASSERT_VALID não fará nada. Na versão de depuração, ele valida o ponteiro, verificações em relação a NULL e chama o objeto próprio `AssertValid` funções de membro. Se qualquer um desses testes falhar, uma mensagem de alerta é exibida da mesma maneira como [ASSERT](#assert).

> [!NOTE]
>  Esta função está disponível somente na versão de depuração do MFC.

Para obter mais informações e exemplos, consulte [depuração de aplicativos do MFC](/visualstudio/debugger/mfc-debugging-techniques).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#19](../../mfc/codesnippet/cpp/diagnostic-services_5.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="debug_new"></a>  DEBUG_NEW

Ajuda a localizar vazamentos de memória.

```
#define  new DEBUG_NEW
```

### <a name="remarks"></a>Comentários

Você pode usar DEBUG_NEW em qualquer lugar no seu programa, normalmente, você usaria o **novo** operador para alocar o armazenamento de heap.

No modo de depuração (quando o **Debug** símbolo é definido), DEBUG_NEW mantém o controle do nome de arquivo e número de linha para cada objeto que aloca. Em seguida, quando você usa o [CMemoryState::DumpAllObjectsSince](cmemorystate-structure.md#dumpallobjectssince) função de membro, cada objeto alocada com DEBUG_NEW é mostrada com o nome de arquivo e número de linha onde ele foi alocado.

Para usar DEBUG_NEW, insira a seguinte diretiva no seus arquivos de origem:

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/diagnostic-services_1.cpp)]

Depois de inserir essa diretiva, o pré-processador irá inserir DEBUG_NEW sempre que você usa **novo**, e MFC faz o resto. Quando você compila uma versão de lançamento do seu programa, DEBUG_NEW resolve para um simples **novo** operação e as informações de número de linha e de nome de arquivo não são gerados.

> [!NOTE]
>  Nas versões anteriores do MFC (4.1 e anterior) necessário para colocar o `#define` instrução depois de todas as instruções que as macros IMPLEMENT_DYNCREATE ou IMPLEMENT_SERIAL de chamada. Isso não é mais necessário.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="debug_only"></a>  DEBUG_ONLY

No modo de depuração (quando o **Debug** símbolo é definido), DEBUG_ONLY avalia seu argumento.

```
DEBUG_ONLY(expression)
```

### <a name="remarks"></a>Comentários

Em uma compilação de versão, DEBUG_ONLY não avalia seu argumento. Isso é útil quando você tiver um código que deve ser executado apenas em compilações de depuração.

A macro DEBUG_ONLY é equivalente ao redor *expressão* com `#ifdef _DEBUG` e `#endif`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#32](../../mfc/codesnippet/cpp/diagnostic-services_6.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

### <a name="ensure"></a>  Certifique-se e ENSURE_VALID

Use para validar a exatidão dos dados.

### <a name="syntax"></a>Sintaxe

```
ENSURE(  booleanExpression )
ENSURE_VALID( booleanExpression  )
```

### <a name="parameters"></a>Parâmetros

*booleanExpression*<br/>
Especifica uma expressão booleana a ser testado.

### <a name="remarks"></a>Comentários

A finalidade dessas macros é melhorar a validação de parâmetros. As macros impedem processamento adicional de parâmetros incorretos em seu código. Ao contrário de macros ASSERT, macros Certifique-se lançar uma exceção além de gerar uma declaração.

As macros se comportam de duas maneiras, de acordo com a configuração do projeto. As macros chamar ASSERT e, em seguida, geram uma exceção se a asserção falhará. Assim, em configurações de depuração (ou seja, quando Debug é definido) as macros de produzem uma asserção e uma exceção ao mesmo tempo em configurações de versão, a produção de macros somente a exceção (ASSERT não avalia a expressão em configurações de versão).

A macro ENSURE_ARG atua como a macro Certifique-se.

ENSURE_VALID chama a macro ASSERT_VALID (que tem um efeito somente em compilações de depuração). Além disso, ENSURE_VALID gera uma exceção se o ponteiro é NULL. O teste NULL é executado em configurações de depuração e versão.

Se qualquer um desses testes falhar, uma mensagem de alerta é exibida da mesma maneira como o ASSERT. A macro gera uma exceção de argumento inválido, se necessário.
### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

### <a name="see-also"></a>Consulte também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[VERIFIQUE SE](#verify)<br/>
[ATLENSURE](#altensure)

## <a name="this_file"></a> THIS_FILE

Expande para o nome do arquivo que está sendo compilado.

### <a name="syntax"></a>Sintaxe

```
THIS_FILE
```

### <a name="remarks"></a>Comentários

As informações são usadas pelas macros ASSERT e verificar. Os assistentes de código e o Assistente de aplicativo colocar a macro em arquivos de código-fonte que criaram.

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

### <a name="see-also"></a>Consulte também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[ASSERT](#assert)<br/>
[VERIFIQUE SE](#verify)

##  <a name="trace"></a>  RASTREAMENTO

Envia a cadeia de caracteres especificada para o depurador do aplicativo atual.

```
TRACE(exp)
TRACE(DWORD  category,  UINT  level, LPCSTR lpszFormat, ...)
```

### <a name="remarks"></a>Comentários

Ver [ATLTRACE2](../../atl/reference/debugging-and-error-reporting-macros.md#atltrace2) para obter uma descrição de rastreamento. RASTREAMENTO e ATLTRACE2 têm o mesmo comportamento.

Na versão de depuração do MFC, essa macro envia a cadeia de caracteres especificada para o depurador do aplicativo atual. Na compilação de versão, essa macro é compilado para nada (nenhum código é gerado em todos os).

Para obter mais informações, consulte [depuração de aplicativos do MFC](/visualstudio/debugger/mfc-debugging-techniques).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="verify"></a>  VERIFIQUE SE

Na versão de depuração do MFC, avalia seu argumento.

```
VERIFY(booleanExpression)
```

### <a name="parameters"></a>Parâmetros

*booleanExpression*<br/>
Especifica uma expressão (incluindo valores de ponteiro) que é avaliada como diferente de zero ou igual a 0.

### <a name="remarks"></a>Comentários

Se o resultado é 0, a macro imprime uma mensagem de diagnóstico e interrompe o programa. Se a condição for diferente de zero, ele não fará nada.

A mensagem de diagnóstico tem o formato

`assertion failed in file <name> in line <num>`

em que *nome* é o nome do arquivo de origem e *num* é o número de linha da asserção que falhou no arquivo de origem.

Na versão de lançamento do MFC, verifique se avalia a expressão, mas não imprimir ou interrompa o programa. Por exemplo, se a expressão for uma chamada de função, a chamada será feita.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#198](../../mfc/codesnippet/cpp/diagnostic-services_7.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="cdumpcontext_in_mfc"></a>  afxDump (CDumpContext em MFC)

Fornece a capacidade básica de despejo de objeto em seu aplicativo.

```
CDumpContext  afxDump;
```

### <a name="remarks"></a>Comentários

`afxDump` é um modelo predefinido [CDumpContext](../../mfc/reference/cdumpcontext-class.md) objeto que permite que você envie `CDumpContext` informações na janela de saída do depurador ou para um terminal de depuração. Normalmente, você fornecer `afxDump` como um parâmetro para `CObject::Dump`.

No Windows NT e todas as versões do Windows, `afxDump` saída é enviada para a janela de saída de depuração do Visual C++, quando você depura seu aplicativo.

Essa variável é definida apenas na versão de depuração do MFC. Para obter mais informações sobre `afxDump`, consulte [Depurando aplicativos do MFC](/visualstudio/debugger/mfc-debugging-techniques).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#23](../../mfc/codesnippet/cpp/diagnostic-services_8.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="afxdump"></a> AfxDump (interno)

Função interna que usa o MFC para despejar o estado de um objeto durante a depuração.

### <a name="syntax"></a>Sintaxe

```
void AfxDump(const CObject* pOb);
```

### <a name="parameters"></a>Parâmetros

*caixa postal*<br/>
Um ponteiro para um objeto de uma classe derivada de `CObject`.

### <a name="remarks"></a>Comentários

`AfxDump` chama um objeto `Dump` função de membro e envia as informações para o local especificadas pelo `afxDump` variável. `AfxDump` está disponível somente na versão de depuração do MFC.

O código do programa não deve chamar `AfxDump`, mas em vez disso, deve chamar o `Dump` a função de membro do objeto apropriado.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

### <a name="see-also"></a>Consulte também

[CObject::Dump](cobject-class.md#dump)

##  <a name="afxmemdf"></a>  afxMemDF

Essa variável pode ser acessado de um depurador ou o seu programa e permite que você ajuste o diagnóstico de alocação.

```
int  afxMemDF;
```

### <a name="remarks"></a>Comentários

`afxMemDF` pode ter os seguintes valores conforme especificado pela enumeração `afxMemDF`:

- `allocMemDF` Ativa o alocador de depuração (configuração padrão na biblioteca de depuração).

- `delayFreeMemDF` Atrasos na liberação de memória. Enquanto seu programa libera um bloco de memória, o alocador não retorna se a memória para o sistema operacional subjacente. Isso colocará o estresse de máximo de memória em seu programa.

- `checkAlwaysMemDF` Chamadas `AfxCheckMemory` sempre que a memória é alocada ou liberada. Isso reduzirá significativamente desalocações e alocações de memória.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#30](../../mfc/codesnippet/cpp/diagnostic-services_9.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="afxcheckerror"></a>  AfxCheckError

Essa função testa a SCODE passado para ver se ele é um erro.

```
void AFXAPI AfxCheckError(SCODE sc);
throw CMemoryException*
throw COleException*
```

### <a name="remarks"></a>Comentários

Se for um erro, a função gera uma exceção. Se o SCODE passado é E_OUTOFMEMORY, a função gerará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) chamando [AfxThrowMemoryException](exception-processing.md#afxthrowmemoryexception). Caso contrário, a função lançará um [COleException](../../mfc/reference/coleexception-class.md) chamando [AfxThrowOleException](exception-processing.md#afxthrowoleexception).

Essa função pode ser usada para verificar os valores de retorno de chamadas para funções OLE em seu aplicativo. Testando o valor retornado com essa função em seu aplicativo, você pode reagir corretamente a condições de erro com uma quantidade mínima de código.

> [!NOTE]
>  Essa função tem o mesmo efeito na depuração e compilações sem depuração.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#33](../../mfc/codesnippet/cpp/diagnostic-services_10.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="afxcheckmemory"></a>  AfxCheckMemory

Essa função valida o pool de memória livre e imprime mensagens de erro conforme necessário.

```
BOOL  AfxCheckMemory();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se não há erros de memória; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se a função não detectar nenhuma corrupção de memória, ele imprime nada.

Todos os blocos de memória atualmente alocados no heap são verificados, incluindo aqueles alocada pelo **novos** mas não os alocado por chamadas diretas para alocadores de memória subjacente, como o **malloc** função ou o `GlobalAlloc` função do Windows. Se qualquer bloco for encontrado para ser corrompidos, uma mensagem é impresso na saída do depurador.

Se você incluir a linha

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/diagnostic-services_1.cpp)]

em um módulo do programa, as chamadas subsequentes, em seguida, para `AfxCheckMemory` mostrar o nome de arquivo e número de linha em que a memória foi alocada.

> [!NOTE]
>  Se o módulo contiver uma ou mais implementações de classes serializáveis, você deve colocar o `#define` linha após a última chamada de macro IMPLEMENT_SERIAL.

Essa função funciona apenas na versão de depuração do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#26](../../mfc/codesnippet/cpp/diagnostic-services_11.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="afxdump"></a>  AfxDump (MFC)

Chame essa função no depurador para despejar o estado de um objeto durante a depuração.

```
void AfxDump(const CObject* pOb);
```

### <a name="parameters"></a>Parâmetros

*caixa postal*<br/>
Um ponteiro para um objeto de uma classe derivada de `CObject`.

### <a name="remarks"></a>Comentários

`AfxDump` chama um objeto `Dump` função de membro e envia as informações para o local especificadas pelo `afxDump` variável. `AfxDump` está disponível somente na versão de depuração do MFC.

O código do programa não deve chamar `AfxDump`, mas em vez disso, deve chamar o `Dump` a função de membro do objeto apropriado.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

### <a name="see-also"></a>Consulte também

[CObject::Dump](cobject-class.md#dump)

##  <a name="afxdumpstack"></a>  AfxDumpStack

Essa função global pode ser usada para gerar uma imagem da pilha atual.

```
void AFXAPI AfxDumpStack(DWORD dwTarget = AFX_STACK_DUMP_TARGET_DEFAULT);
```

### <a name="parameters"></a>Parâmetros

*dwTarget*<br/>
Indica o destino da saída de despejo. Valores possíveis, que podem ser combinados usando o OR bit a bit ( **&#124;**) são de operador, da seguinte maneira:

- AFX_STACK_DUMP_TARGET_TRACE envia a saída por meio das [rastreamento](#trace) macro. A macro TRACE gera a saída em compilações de depuração. ele gera nenhuma saída em compilações de versão. Além disso, o rastreamento pode ser redirecionado para outros destinos, além do depurador.

- AFX_STACK_DUMP_TARGET_DEFAULT envia a saída de despejo para o destino padrão. Para uma compilação de depuração, a saída vai para a macro TRACE. Em uma compilação de versão, a saída vai para a área de transferência.

- AFX_STACK_DUMP_TARGET_CLIPBOARD envia a saída apenas na área de transferência. Os dados são colocados na área de transferência como texto sem formatação usando o formato de área de transferência CF_TEXT.

- AFX_STACK_DUMP_TARGET_BOTH envia a saída para a área de transferência e a macro TRACE, ao mesmo tempo.

- AFX_STACK_DUMP_TARGET_ODS envia a saída diretamente para o depurador por meio da função Win32 `OutputDebugString()`. Esta opção gerar a saída do depurador em ambos os debug e builds de lançamento quando um depurador é anexado ao processo. AFX_STACK_DUMP_TARGET_ODS atinge o depurador sempre (se ele estiver anexado) e não pode ser redirecionada.

### <a name="remarks"></a>Comentários

O exemplo a seguir reflete uma única linha da saída gerada de chamar `AfxDumpStack` de um manipulador de botão em um aplicativo de caixa de diálogo do MFC:

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

Cada linha na saída acima indica o endereço da última chamada de função, o nome de caminho completo do módulo que contém a chamada de função e o protótipo de função chamada. Se a chamada de função na pilha não ocorre no endereço exato da função, é mostrado um deslocamento de bytes.

Por exemplo, a tabela a seguir descreve a primeira linha da saída acima:

|Saída|Descrição|
|------------|-----------------|
|`00427D55:`|O endereço de retorno da última chamada de função.|
|`DUMP2\DEBUG\DUMP2.EXE!`|O nome de caminho completo do módulo que contém a chamada de função.|
|`void AfxDumpStack(unsigned long)`|O protótipo de função chamada.|
|`+ 181 bytes`|O deslocamento em bytes do endereço do protótipo da função (nesse caso, `void AfxDumpStack(unsigned long)`) para o endereço de retorno (nesse caso, `00427D55`).|

`AfxDumpStack` está disponível nas versões de depuração e nondebug das bibliotecas MFC; No entanto, a função é sempre vinculada estaticamente, mesmo quando seu arquivo executável usa MFC em uma DLL compartilhada. Em implementações de biblioteca compartilhada, a função é encontrada no MFCS42. Biblioteca LIB (e suas variantes).

Para usar essa função com êxito:

- O arquivo IMAGEHLP. DLL deve estar em seu caminho. Se você não tiver essa DLL, a função exibirá uma mensagem de erro. Ver [biblioteca de ajuda de imagem](/windows/desktop/Debug/image-help-library) para obter informações sobre o conjunto de funções fornecida pelo IMAGEHLP.

- Os módulos que têm os quadros na pilha devem incluir informações de depuração. Se eles não contêm informações de depuração, a função ainda irá gerar um rastreamento de pilha, mas o rastreamento será menos detalhado.
### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="afxenablememoryleakdump"></a>  AfxEnableMemoryLeakDump

Habilita e desabilita o despejo de vazamento de memória no destruidor AFX_DEBUG_STATE.

```
BOOL AFXAPI AfxEnableMemoryLeakDump(BOOL bDump);
```

### <a name="parameters"></a>Parâmetros

*bDump*<br/>
[in] TRUE indica que o despejo de vazamento de memória estiver habilitado; FALSE indica que o despejo de vazamento de memória está desabilitado.

### <a name="return-value"></a>Valor de retorno

O valor anterior para esse sinalizador.

### <a name="remarks"></a>Comentários

Quando um aplicativo descarrega a biblioteca MFC, a biblioteca MFC verifica se há vazamentos de memória. Neste ponto, quaisquer perdas de memória são relatadas para o usuário por meio de **depurar** janela do Visual Studio.

Se seu aplicativo for carregada em outra biblioteca antes da biblioteca MFC, algumas alocações de memória nessa biblioteca serão relatadas incorretamente como vazamentos de memória. Vazamentos de memória False podem causar a seu aplicativo fechar lentamente, como a biblioteca MFC relata-los. Nesse caso, use `AfxEnableMemoryLeakDump` para desabilitar o despejo de vazamento de memória.

> [!NOTE]
>  Se você usar esse método para desativar o despejo de vazamento de memória, você não receberá os relatórios de vazamentos de memória válido em seu aplicativo. Você só deve usar esse método se você tiver certeza de que o relatório de vazamento de memória contém vazamentos de memória de false.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="afxenablememorytracking"></a>  AfxEnableMemoryTracking

Normalmente, o diagnóstico de memória de rastreamento está habilitado na versão de depuração do MFC.

```
BOOL AfxEnableMemoryTracking(BOOL bTrack);
```

### <a name="parameters"></a>Parâmetros

*bTrack*<br/>
Definir esse valor como TRUE ativa na memória de rastreamento; FALSE o desativa.

### <a name="return-value"></a>Valor de retorno

A configuração anterior do sinalizador de habilitação do rastreamento.

### <a name="remarks"></a>Comentários

Use esta função para desabilitar o controle em seções do seu código que você sabe que está alocando os blocos corretamente.

Para obter mais informações sobre `AfxEnableMemoryTracking`, consulte [Depurando aplicativos do MFC](/visualstudio/debugger/mfc-debugging-techniques).

> [!NOTE]
>  Essa função funciona apenas na versão de depuração do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#24](../../mfc/codesnippet/cpp/diagnostic-services_12.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="afxismemoryblock"></a>  AfxIsMemoryBlock

Testa um endereço de memória para certificar-se de que ele representa um bloco de memória ativa no momento que foi alocado pela versão do diagnóstico **novo**.

```
BOOL AfxIsMemoryBlock(
    const void* p,
    UINT nBytes,
    LONG* plRequestNumber = NULL);
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Aponta para o bloco de memória a ser testado.

*nBytes*<br/>
Contém a duração do bloco de memória em bytes.

*plRequestNumber*<br/>
Aponta para um **longo** inteiro que será preenchido com o número de sequência de alocação do bloco de memória, ou zero se ele não representa um bloco de memória ativa no momento.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o bloco de memória alocado no momento e o tamanho correto; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Ele também verifica o tamanho especificado em relação ao tamanho alocado original. Se a função retorna não zero, o número de sequência de alocação é retornado no *plRequestNumber*. Esse número representa a ordem na qual o bloco foi alocado em relação a todos os outros **novo** alocações.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#27](../../mfc/codesnippet/cpp/diagnostic-services_13.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="afxisvalidaddress"></a>  AfxIsValidAddress

Testes de qualquer endereço de memória para garantir que ele está contido inteiramente dentro do espaço de memória do programa.

```
BOOL AfxIsValidAddress(
    const void* lp,
    UINT nBytes,
    BOOL bReadWrite = TRUE);
```

### <a name="parameters"></a>Parâmetros

*LP*<br/>
Aponta para o endereço de memória a ser testado.

*nBytes*<br/>
Contém o número de bytes de memória a ser testado.

*bReadWrite*<br/>
Especifica se a memória é tanto para leitura e gravação (TRUE) ou apenas leitura (FALSE).

### <a name="return-value"></a>Valor de retorno

Em compilações de depuração, diferente de zero se o bloco de memória especificado está contido inteiramente dentro do espaço de memória do programa; Caso contrário, 0.

Em compilações sem depuração, diferente de zero se *lp* não for NULL; caso contrário, 0.

### <a name="remarks"></a>Comentários

O endereço não está restrito a blocos alocados por **novo**.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#28](../../mfc/codesnippet/cpp/diagnostic-services_14.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="afxisvalidstring"></a>  AfxIsValidString

Use esta função para determinar se um ponteiro para uma cadeia de caracteres é válido.

```
BOOL  AfxIsValidString(
    LPCSTR lpsz,
    int nLength = -1);
```

### <a name="parameters"></a>Parâmetros

*lpsz*<br/>
O ponteiro para testar.

*nLength*<br/>
Especifica o comprimento da cadeia de caracteres a ser testado, em bytes. Um valor de -1 indica que a cadeia de caracteres seja terminada em nulo.

### <a name="return-value"></a>Valor de retorno

Em compilações de depuração, diferente de zero se o ponteiro especificado aponta para uma cadeia de caracteres do tamanho especificado; Caso contrário, 0.

Em compilações sem depuração, diferente de zero se *lpsz* não for NULL; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#29](../../mfc/codesnippet/cpp/diagnostic-services_15.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="afxsetallochook"></a>  AfxSetAllocHook

Define um gancho que permite a chamada da função especificada antes de cada bloco de memória é alocado.

```
AFX_ALLOC_HOOK AfxSetAllocHook(AFX_ALLOC_HOOK pfnAllocHook);
```

### <a name="parameters"></a>Parâmetros

*pfnAllocHook*<br/>
Especifica o nome da função a ser chamada. Consulte os comentários para o protótipo de uma função de alocação.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se você deseja permitir a alocação; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O alocador de memória de depuração da biblioteca Microsoft Foundation Class pode chamar uma função de gancho definidas pelo usuário para permitir que o usuário para monitorar uma alocação de memória e para controlar se a alocação é permitida. Funções de gancho de alocação são com protótipo, da seguinte maneira:

**BOOL AFXAPI AllocHook (size_t** `nSize` **, BOOL** `bObject` **longo** `lRequestNumber` **);**

*nSize*<br/>
O tamanho da alocação de memória proposto.

*bO*<br/>
TRUE se a alocação é para um `CObject`-objeto derivada; caso contrário, FALSE.

*lRequestNumber*<br/>
Número de sequência da alocação de memória.

Observe que a convenção de chamada de AFXAPI implica que o receptor deve remover os parâmetros da pilha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="afxdoforallclasses"></a>  AfxDoForAllClasses

Chama a função de iteração especificada para todos os serializável `CObject`-classes derivadas no espaço de memória do aplicativo.

```
void
AFXAPI AfxDoForAllClasses(
    void (* pfn)(const CRuntimeClass* pClass, void* pContext),
    void* pContext);
```

### <a name="parameters"></a>Parâmetros

*pfn*<br/>
Aponta para uma função de iteração a ser chamado para cada classe. Os argumentos de função são um ponteiro para um `CRuntimeClass` objeto e um ponteiro nulo para os dados extras que o chamador fornecer à função.

*pContext*<br/>
Aponta para dados opcionais que o chamador pode fornecer para a função de iteração. Esse ponteiro pode ser NULL.

### <a name="remarks"></a>Comentários

Serializável `CObject`-as classes derivadas são classes derivadas usando a macro DECLARE_SERIAL. O ponteiro que é passado para `AfxDoForAllClasses` na *pContext* é passado para a função de iteração especificada toda vez que é chamado.

> [!NOTE]
>  Essa função funciona apenas na versão de depuração do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#113](../../mfc/codesnippet/cpp/diagnostic-services_16.cpp)]

[!code-cpp[NVC_MFCCollections#114](../../mfc/codesnippet/cpp/diagnostic-services_17.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="afxdoforallobjects"></a>  AfxDoForAllObjects

Executa a função de iteração especificada para todos os objetos derivam de `CObject` que foram alocados **nova**.

```
void AfxDoForAllObjects(
    void (* pfn)(CObject* pObject, void* pContext),
    void* pContext);
```

### <a name="parameters"></a>Parâmetros

*pfn*<br/>
Aponta para uma função de iteração a ser executada para cada objeto. Os argumentos de função são um ponteiro para um `CObject` e um ponteiro nulo para os dados extras que o chamador fornecer à função.

*pContext*<br/>
Aponta para dados opcionais que o chamador pode fornecer para a função de iteração. Esse ponteiro pode ser NULL.

### <a name="remarks"></a>Comentários

Pilha, global, ou objetos inseridos não são enumeradas. O ponteiro é passado para `AfxDoForAllObjects` na *pContext* é passado para a função de iteração especificada toda vez que é chamado.

> [!NOTE]
>  Essa função funciona apenas na versão de depuração do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#115](../../mfc/codesnippet/cpp/diagnostic-services_18.cpp)]

[!code-cpp[NVC_MFCCollections#116](../../mfc/codesnippet/cpp/diagnostic-services_19.cpp)]

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)