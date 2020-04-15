---
title: Macros de depuração e relatório de erros
ms.date: 05/06/2019
f1_keywords:
- atldef/ATL::_ATL_DEBUG_INTERFACES
- atldef/ATL::_ATL_DEBUG_QI
- atldef/ATL::ATLASSERT
- afx/ATL::ATLENSURE
- atltrace/ATL::ATLTRACENOTIMPL
- atltrace/ATL::ATLTRACE
helpviewer_keywords:
- macros, error reporting
ms.assetid: 4da9b87f-ec5c-4a32-ab93-637780909b9d
ms.openlocfilehash: 69ab6e17bfb1ec85ddb5b8c19c18010a9b4f3df6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330194"
---
# <a name="debugging-and-error-reporting-macros"></a>Macros de depuração e relatório de erros

Essas macros fornecem instalações úteis de depuração e rastreamento.

|||
|-|-|
|[_ATL_DEBUG_INTERFACES](#_atl_debug_interfaces)|Grava, na janela de saída, quaisquer vazamentos de interface que são detectados quando `_Module.Term` são chamados.|
|[_ATL_DEBUG_QI](#_atl_debug_qi)|Grava todas `QueryInterface` as chamadas para a janela de saída.|
|[Atlassert](#atlassert)|Executa a mesma funcionalidade que a [_ASSERTE](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) macro encontrada na biblioteca de tempo de execução C.|
|[Atlensure](#atlensure)|Realiza validação de parâmetros. Ligue `AtlThrow` se necessário|
|[ATLTRACENOTIMPL](#atltracenotimpl)|Envia uma mensagem ao dispositivo de despejo de que a função especificada não é implementada.|
|[Atltrace](#atltrace)|Relata avisos a um dispositivo de saída, como a janela de depurador, de acordo com as bandeiras e níveis indicados. Incluído para compatibilidade retrógrada.|
|[ATLTRACE2](#atltrace2)|Relata avisos a um dispositivo de saída, como a janela de depurador, de acordo com as bandeiras e níveis indicados.|

## <a name="_atl_debug_interfaces"></a><a name="_atl_debug_interfaces"></a>_ATL_DEBUG_INTERFACES

Defina esta macro antes de incluir `AddRef` quaisquer `Release` arquivos de cabeçalho ATL para rastrear todos e chamadas nas interfaces de seus componentes para a janela de saída.

```
#define _ATL_DEBUG_INTERFACES
```

### <a name="remarks"></a>Comentários

A saída de rastreamento aparecerá conforme mostrado abaixo:

`ATL: QIThunk - 2008         AddRef  :   Object = 0x00d81ba0   Refcount = 1   CBug - IBug`

A primeira parte de cada `ATL: QIThunk`traço será sempre. Em seguida, é um valor que identifica a interface particular *que* está sendo usada. Um thunk de interface é um objeto usado para manter uma contagem de referência e fornecer o recurso de rastreamento usado aqui. Um novo thunk de interface é `QueryInterface` criado em `IUnknown` cada chamada, exceto para solicitações para a interface (neste caso, o mesmo thunk é devolvido todas as vezes para cumprir as regras de identidade da COM).

Em seguida, `AddRef` você `Release` verá ou indicará qual método foi chamado. Depois disso, você verá um valor identificando o objeto cuja contagem de referência da interface foi alterada. O valor rastreado é **o** ponteiro do objeto.

A contagem de referência que é traçada `AddRef` é `Release` a contagem de referência nesse thunk depois ou foi chamado. Observe que esta contagem de referência pode não corresponder à contagem de referência para o objeto. Cada thunk mantém sua própria contagem de referências para ajudá-lo a cumprir totalmente as regras de contagem de referência da COM.

A última informação rastreada é o nome do objeto `AddRef` e `Release` a interface sendo afetada pela ou chamada.

Quaisquer vazamentos de interface detectados quando `_Module.Term` o servidor é desligado e é chamado será registrado assim:

`ATL: QIThunk - 2005         LEAK    :   Object = 0x00d81ca0   Refcount = 1   MaxRefCount = 1   CBug - IBug`

As informações fornecidas aqui mapeiam diretamente as informações fornecidas nas instruções de rastreamento anteriores, para que você possa examinar as contagens de referência durante toda a vida de uma interface thunk. Além disso, você recebe uma indicação da contagem máxima de referência nesse thunk de interface.

> [!NOTE]
> _ATL_DEBUG_INTERFACES pode ser usado em construções de varejo.

## <a name="_atl_debug_qi"></a><a name="_atl_debug_qi"></a>_ATL_DEBUG_QI

Grava todas `QueryInterface` as chamadas para a janela de saída.

```
#define _ATL_DEBUG_QI
```

### <a name="remarks"></a>Comentários

Se uma `QueryInterface` chamada falhar, a janela de saída será exibida:

*nome da interface* - `failed`

## <a name="atlassert"></a><a name="atlassert"></a>Atlassert

A macro ATLASSERT executa a mesma funcionalidade que a [_ASSERTE](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) macro encontrada na biblioteca de tempo de execução C.

```
ATLASSERT(booleanExpression);
```

### <a name="parameters"></a>Parâmetros

*Booleanexpression*<br/>
Expressão (incluindo ponteiros) que avalia para não zero ou 0.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, o ATLASSERT avalia *booleanExpression* e gera um relatório de depuração quando o resultado é falso.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldef.h

## <a name="atlensure"></a><a name="atlensure"></a>Atlensure

Esta macro é usada para validar parâmetros passados para uma função.

```
ATLENSURE(booleanExpression);
ATLENSURE_THROW(booleanExpression, hr);
```

### <a name="parameters"></a>Parâmetros

*Booleanexpression*<br/>
Especifica uma expressão booleana a ser testada.

*Hr*<br/>
Especifica um código de erro para retornar.

### <a name="remarks"></a>Comentários

Essas macros fornecem um mecanismo para detectar e notificar o usuário sobre o uso incorreto de parâmetros.

A macro chama ATLASSERT e `AtlThrow`se a condição falhar chamadas .

No caso ATLENSURE, `AtlThrow` é chamado com E_FAIL.

No caso ATLENSURE_THROW, `AtlThrow` é chamado com o HRESULT especificado.

A diferença entre ATLENSURE e ATLASSERT é que o ATLENSURE lança uma exceção nas compilações de release, bem como em compilações de depuração.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#108](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="atltracenotimpl"></a><a name="atltracenotimpl"></a>ATLTRACENOTIMPL

Nas compilações de depuração do ATL, envia a string " *funcname* não é implementada" para o dispositivo de despejo e retorna E_NOTIMPL.

```
ATLTRACENOTIMPL(funcname);
```

### <a name="parameters"></a>Parâmetros

*Funcname*<br/>
[em] Uma seqüência contendo o nome da função que não é implementada.

### <a name="remarks"></a>Comentários

Nas compilações de lançamento, simplesmente retorna E_NOTIMPL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#127](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_2.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltrace.h

## <a name="atltrace"></a><a name="atltrace"></a>Atltrace

Relata avisos a um dispositivo de saída, como a janela de depurador, de acordo com as bandeiras e níveis indicados. Incluído para compatibilidade retrógrada.

```
ATLTRACE(exp);

ATLTRACE(
    DWORD category,
    UINT  level,
    LPCSTR lpszFormat, ...);
```

### <a name="parameters"></a>Parâmetros

*Exp*<br/>
[em] A seqüência e as variáveis a serem enviadas para a janela de saída ou qualquer aplicativo que aprisione essas mensagens.

*Categoria*<br/>
[em] Tipo de evento ou método sobre o qual relatar. Consulte as Observações para uma lista de categorias.

*Nível*<br/>
[em] O nível de rastreamento para relatar. Consulte os Comentários para mais detalhes.

*lpszFormat*<br/>
[em] A seqüência formatada para enviar para o dispositivo de despejo.

### <a name="remarks"></a>Comentários

Consulte [ATLTRACE2](#atltrace2) para obter uma descrição do ATLTRACE. ATLTRACE e ATLTRACE2 têm o mesmo comportamento, o ATLTRACE está incluído para compatibilidade retrógrada.

## <a name="atltrace2"></a><a name="atltrace2"></a>ATLTRACE2

Relata avisos a um dispositivo de saída, como a janela de depurador, de acordo com as bandeiras e níveis indicados.

```
ATLTRACE2(exp);

ATLTRACE2(
    DWORD category,
    UINT level,
    LPCSTR lpszFormat,  ...);
```

### <a name="parameters"></a>Parâmetros

*Exp*<br/>
[em] A seqüência de caracteres a ser enviada para a janela de saída ou qualquer aplicativo que aprisione essas mensagens.

*Categoria*<br/>
[em] Tipo de evento ou método sobre o qual relatar. Consulte as Observações para uma lista de categorias.

*Nível*<br/>
[em] O nível de rastreamento para relatar. Consulte os Comentários para mais detalhes.

*lpszFormat*<br/>
[em] A `printf`seqüência de formato de estilo a ser usada para criar uma string para enviar para o dispositivo de despejo.

### <a name="remarks"></a>Comentários

A forma curta de ATLTRACE2 grava uma seqüência na janela de saída do depurador. A segunda forma de ATLTRACE2 também grava a saída na janela de saída do depurador, mas está sujeita às configurações da ferramenta de rastreamento ATL/MFC (ver [ATLTraceTool Sample](../../overview/visual-cpp-samples.md)). Por exemplo, se você definir *o nível* para 4 e a ferramenta de rastreamento ATL/MFC para o nível 0, você não verá a mensagem. *nível* pode ser 0, 1, 2, 3 ou 4. A inadimplência, 0, relata apenas os problemas mais graves.

O parâmetro *de categoria* lista as bandeiras de rastreamento a serem definidas. Essas bandeiras correspondem aos tipos de métodos para os quais você deseja relatar. As tabelas abaixo listam os sinalizadores de rastreamento válidos que você pode usar para o parâmetro de *categoria.*

### <a name="atl-trace-flags"></a>Bandeiras de rastreamento ATL

|Categoria ATL|Descrição|
|------------------|-----------------|
|`atlTraceGeneral`|Relatórios de todos os aplicativos ATL. O padrão.|
|`atlTraceCOM`|Relatórios sobre métodos COM.|
|`atlTraceQI`|Relatórios sobre chamadas de QueryInterface.|
|`atlTraceRegistrar`|Relatórios sobre o registro de objetos.|
|`atlTraceRefcount`|Relatórios sobre a alteração da contagem de referências.|
|`atlTraceWindowing`|Relatórios sobre métodos de windows; por exemplo, relata um ID de mapa de mensagem inválido.|
|`atlTraceControls`|Relatórios sobre controles; por exemplo, relata quando um controle ou sua janela é destruída.|
|`atlTraceHosting`|Reporta mensagens de hospedagem; por exemplo, relata quando um cliente em um contêiner é ativado.|
|`atlTraceDBClient`|Relatórios sobre o modelo de consumo do OLE DB; por exemplo, quando uma chamada para GetData falha, a saída pode conter o HRESULT.|
|`atlTraceDBProvider`|Relatórios sobre o modelo do provedor OLE DB; por exemplo, relata se a criação de uma coluna falhou.|
|`atlTraceSnapin`|Relatórios para o aplicativo MMC SnapIn.|
|`atlTraceNotImpl`|Informa que a função indicada não é implementada.|
|`atlTraceAllocation`|Relata mensagens impressas pelas ferramentas de depuração de memória em atldbgmem.h.|

### <a name="mfc-trace-flags"></a>Sinalizadores de rastreamento MFC

|Categoria MFC|Descrição|
|------------------|-----------------|
|`traceAppMsg`|Propósito geral, mensagens de MFC. Sempre recomendado.|
|`traceDumpContext`|Mensagens de [CDumpContext](../../mfc/reference/cdumpcontext-class.md).|
|`traceWinMsg`|Mensagens do código de manipulação de mensagens da MFC.|
|`traceMemory`|Mensagens do código de gerenciamento de memória do MFC.|
|`traceCmdRouting`|Mensagens do código de roteamento de comando do Windows do MFC.|
|`traceHtml`|Mensagens do suporte de diálogo DHTML do MFC.|
|`traceSocket`|Mensagens do suporte ao soquete do MFC.|
|`traceOle`|Mensagens do suporte oLE do MFC.|
|`traceDatabase`|Mensagens do suporte de banco de dados do MFC.|
|`traceInternet`|Mensagens do suporte à Internet do MFC.|

Para declarar uma categoria de rastreamento personalizado, declare uma instância global da classe da `CTraceCategory` seguinte forma:

[!code-cpp[NVC_ATL_Utilities#109](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_3.cpp)]

O nome da categoria, MY_CATEGORY neste exemplo, é o nome especificado para o parâmetro *de categoria.* O primeiro parâmetro é o nome da categoria que aparecerá na ferramenta de rastreamento ATL/MFC. O segundo parâmetro é o nível de rastreamento padrão. Este parâmetro é opcional, e o nível de rastreamento padrão é 0.

Para usar uma categoria definida pelo usuário:

[!code-cpp[NVC_ATL_Utilities#110](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_4.cpp)]

Para especificar que deseja filtrar as mensagens de rastreamento, insira definições para essas macros em Stdafx.h antes da `#include <atlbase.h>` instrução.

Alternativamente, você pode definir o filtro nas diretivas do pré-processador na caixa de diálogo **Páginas** de propriedade. Clique na guia **Pré-processador** e, em seguida, insira o global na caixa de edição **Dedefinições de Pré-processador.**

Atlbase.h contém definições padrão das macros ATLTRACE2 e essas definições serão usadas se você não definir esses símbolos antes que atlbase.h seja processado.

Nas compilações de versão, o ATLTRACE2 compila-se para `(void) 0`.

O ATLTRACE2 limita o conteúdo da seqüência a ser enviada ao dispositivo de despejo para não mais de 1023 caracteres, após a formatação.

ATLTRACE e ATLTRACE2 têm o mesmo comportamento, o ATLTRACE está incluído para compatibilidade retrógrada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#111](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_5.cpp)]

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)<br/>
[Depuração e verificação de funções globais de relatórios](../../atl/reference/debugging-and-error-reporting-global-functions.md)
