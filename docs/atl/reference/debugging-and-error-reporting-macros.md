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
ms.openlocfilehash: a243351ff337cb517f8a8231c18c495c8d2ca302
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221082"
---
# <a name="debugging-and-error-reporting-macros"></a>Macros de depuração e relatório de erros

Essas macros fornecem recursos úteis de depuração e rastreamento.

|||
|-|-|
|[_ATL_DEBUG_INTERFACES](#_atl_debug_interfaces)|Grava na janela de saída, perdas de qualquer interface que são detectados quando `_Module.Term` é chamado.|
|[_ATL_DEBUG_QI](#_atl_debug_qi)|Grava todas as chamadas para `QueryInterface` à janela de saída.|
|[{1&AMP;GT;ATLASSERT&AMP;LT;1](#atlassert)|Executa a mesma funcionalidade que o [asserte](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) macro encontrada na biblioteca de tempo de execução C.|
|[ATLENSURE](#atlensure)|Executa a validação de parâmetros. Chamar `AtlThrow` se necessário|
|[ATLTRACENOTIMPL](#atltracenotimpl)|Envia uma mensagem para o dispositivo de despejo que a função especificada não é implementada.|
|[ATLTRACE](#atltrace)|Relata avisos para um dispositivo de saída, como a janela do depurador, acordo com os sinalizadores indicados e níveis. Incluído para compatibilidade com versões anteriores.|
|[ATLTRACE2](#atltrace2)|Relata avisos para um dispositivo de saída, como a janela do depurador, acordo com os sinalizadores indicados e níveis.|

##  <a name="_atl_debug_interfaces"></a>  _ATL_DEBUG_INTERFACES

Definir essa macro antes de incluir quaisquer arquivos de cabeçalho do ATL para rastrear todos os `AddRef` e `Release` chama em interfaces de seus componentes para a janela de saída.

```
#define _ATL_DEBUG_INTERFACES
```

### <a name="remarks"></a>Comentários

A saída de rastreamento será exibida conforme mostrado abaixo:

`ATL: QIThunk - 2008         AddRef  :   Object = 0x00d81ba0   Refcount = 1   CBug - IBug`

A primeira parte de cada rastreamento sempre será `ATL: QIThunk`. Em seguida, é um valor que identifica a determinada *conversão de interface* que está sendo usado. Conversão de uma interface é um objeto usado para manter uma contagem de referência e fornecem a capacidade de rastreamento usada aqui. Uma conversão de interface nova é criada em cada chamada a `QueryInterface` , exceto para as solicitações para o `IUnknown` interface (nesse caso, a mesma conversão é retornada sempre estar em conformidade com as regras de identidade do COM).

Em seguida você verá `AddRef` ou `Release` que indica qual método foi chamado. Depois disso, você verá um valor que identifica o objeto cuja contagem de referência de interface foi alterada. O valor rastreado é o **isso** ponteiro do objeto.

A contagem de referência que é rastreada é a contagem de referência sobre essa conversão após `AddRef` ou `Release` foi chamado. Observe que a contagem de referência não pode corresponder a contagem de referência para o objeto. Cada conversão mantém seu próprio contagem de referência para ajudá-lo a estar totalmente em conformidade com as regras de contagem de referência do COM.

A parte final do rastreamento de informações é o nome do objeto e a interface que está sendo afetado pela `AddRef` ou `Release` chamar.

Qualquer interface os vazamentos detectados quando o servidor é desligado e `_Module.Term` é chamado será registrado como este:

`ATL: QIThunk - 2005         LEAK    :   Object = 0x00d81ca0   Refcount = 1   MaxRefCount = 1   CBug - IBug`

As informações fornecidas aqui é mapeada diretamente para as informações fornecidas nas instruções de rastreamento anteriores, para que você possa examinar as contagens de referência em todo o tempo de vida inteiro de uma conversão de interface. Além disso, você deve obter uma indicação de que a contagem de referência máximo na conversão dessa interface.

> [!NOTE]
> _ATL_DEBUG_INTERFACES pode ser usado em compilações para venda.

##  <a name="_atl_debug_qi"></a>  _ATL_DEBUG_QI

Grava todas as chamadas para `QueryInterface` à janela de saída.

```
#define _ATL_DEBUG_QI
```

### <a name="remarks"></a>Comentários

Se uma chamada para `QueryInterface` falhou, a janela de saída será exibida:

*interface name* - `failed`

##  <a name="atlassert"></a>  {1&AMP;GT;ATLASSERT&AMP;LT;1

A macro {1&gt;ATLASSERT&lt;1 executa a mesma funcionalidade que o [asserte](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) macro encontrada na biblioteca de tempo de execução C.

```
ATLASSERT(booleanExpression);
```

### <a name="parameters"></a>Parâmetros

*booleanExpression*<br/>
Expressão (incluindo ponteiros) avaliada como diferente de zero ou igual a 0.

### <a name="remarks"></a>Comentários

Em compilações de depuração, avalia {1&gt;ATLASSERT&lt;1 *booleanExpression* e gera um relatório de depuração quando o resultado é false.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldef.h

##  <a name="atlensure"></a>  ATLENSURE

Essa macro é usada para validar os parâmetros passados para uma função.

```
ATLENSURE(booleanExpression);
ATLENSURE_THROW(booleanExpression, hr);
```

### <a name="parameters"></a>Parâmetros

*booleanExpression*<br/>
Especifica uma expressão booleana a ser testado.

*hr*<br/>
Especifica um código de erro para retornar.

### <a name="remarks"></a>Comentários

Essas macros fornecem um mecanismo para detectar e notificar o usuário sobre o uso do parâmetro incorreto.

A macro chama {1&gt;ATLASSERT&lt;1 e se a condição falhar chamadas `AtlThrow`.

No caso de ATLENSURE, `AtlThrow` é chamado com E_FAIL.

No caso de ATLENSURE_THROW, `AtlThrow` é chamado com o HRESULT especificado.

A diferença entre ATLENSURE e {1&gt;ATLASSERT&lt;1 é que ATLENSURE gera uma exceção em builds de versão, bem como em compilações de depuração.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#108](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="atltracenotimpl"></a>  ATLTRACENOTIMPL

Em compilações de depuração da ATL, envia a cadeia de caracteres " *funcname* não está implementado" para o dispositivo de despejo e retornará E_NOTIMPL.

```
ATLTRACENOTIMPL(funcname);
```

### <a name="parameters"></a>Parâmetros

*funcname*<br/>
[in] Uma cadeia de caracteres que contém o nome da função que não está implementado.

### <a name="remarks"></a>Comentários

Em compilações de versão, simplesmente retornará E_NOTIMPL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#127](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_2.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltrace.h

##  <a name="atltrace"></a>  ATLTRACE

Relata avisos para um dispositivo de saída, como a janela do depurador, acordo com os sinalizadores indicados e níveis. Incluído para compatibilidade com versões anteriores.

```
ATLTRACE(exp);

ATLTRACE(
    DWORD category,
    UINT  level,
    LPCSTR lpszFormat, ...);
```

### <a name="parameters"></a>Parâmetros

*exp*<br/>
[in] A cadeia de caracteres e variáveis a serem enviadas para janela de saída ou qualquer aplicativo que intercepta essas mensagens.

*category*<br/>
[in] Tipo de evento ou método no qual a relatório. Consulte os comentários para obter uma lista de categorias.

*level*<br/>
[in] O nível de rastreamento para o relatório. Consulte os comentários para obter detalhes.

*lpszFormat*<br/>
[in] A cadeia de caracteres formatada para enviar para o dispositivo de despejo.

### <a name="remarks"></a>Comentários

Ver [ATLTRACE2](#atltrace2) para obter uma descrição de ATLTRACE. ATLTRACE e ATLTRACE2 têm o mesmo comportamento, ATLTRACE é incluído para compatibilidade com versões anteriores.

##  <a name="atltrace2"></a>  ATLTRACE2

Relata avisos para um dispositivo de saída, como a janela do depurador, acordo com os sinalizadores indicados e níveis.

```
ATLTRACE2(exp);

ATLTRACE2(
    DWORD category,
    UINT level,
    LPCSTRlpszFormat,  ...);
```

### <a name="parameters"></a>Parâmetros

*exp*<br/>
[in] A cadeia de caracteres para enviar para a janela de saída ou qualquer aplicativo que intercepta essas mensagens.

*category*<br/>
[in] Tipo de evento ou método no qual a relatório. Consulte os comentários para obter uma lista de categorias.

*level*<br/>
[in] O nível de rastreamento para o relatório. Consulte os comentários para obter detalhes.

*lpszFormat*<br/>
[in] O `printf`-cadeia de caracteres de formato usar para criar uma cadeia de caracteres para enviar para o dispositivo de despejo de estilo.

### <a name="remarks"></a>Comentários

A forma abreviada de ATLTRACE2 grava uma cadeia de caracteres para a janela de saída do depurador. A segunda forma de ATLTRACE2 também grava a saída para a janela de saída do depurador, mas está sujeito às configurações da ferramenta de rastreamento de ATL/MFC (consulte [ATLTraceTool exemplo](../../overview/visual-cpp-samples.md)). Por exemplo, se você definir *nível* 4 e a ferramenta de rastreamento ATL/MFC para o nível 0, você não verá a mensagem. *nível* pode ser 0, 1, 2, 3 ou 4. O padrão, 0, relata apenas os problemas mais graves.

O *categoria* listas de parâmetros para definir os sinalizadores de rastreamento. Esses sinalizadores correspondem aos tipos de métodos para a qual você deseja relatar. As tabelas abaixo listam os sinalizadores de rastreamento válido que você pode usar para o *categoria* parâmetro.

### <a name="atl-trace-flags"></a>Sinalizadores de rastreamento ATL

|Categoria do ATL|Descrição|
|------------------|-----------------|
|`atlTraceGeneral`|Relatórios em todos os aplicativos da ATL. O padrão.|
|`atlTraceCOM`|Relatórios sobre os métodos.|
|`atlTraceQI`|Relatórios em chamadas de QueryInterface.|
|`atlTraceRegistrar`|Relatórios no registro de objetos.|
|`atlTraceRefcount`|Relatórios sobre como alterar a contagem de referência.|
|`atlTraceWindowing`|Relatórios sobre os métodos do windows; Por exemplo, relata um ID do mapa de mensagem inválida.|
|`atlTraceControls`|Relatórios nos controles; Por exemplo, informa quando um controle ou sua janela é destruída.|
|`atlTraceHosting`|Relatórios de hospedagem mensagens; Por exemplo, informa quando um cliente em um contêiner é ativado.|
|`atlTraceDBClient`|Relatórios no modelo de consumidor do OLE DB; Por exemplo, quando uma chamada para GetData falhar, a saída pode conter o HRESULT.|
|`atlTraceDBProvider`|Relatórios no modelo de provedor do OLE DB; Por exemplo, informa se Falha na criação de uma coluna.|
|`atlTraceSnapin`|Relatórios de aplicativo do snap-in do MMC.|
|`atlTraceNotImpl`|Relata que a função indicada não é implementada.|
|`atlTraceAllocation`|Relata mensagens impressas pela memória ferramentas de depuração em atldbgmem.h.|

### <a name="mfc-trace-flags"></a>Sinalizadores de rastreamento do MFC

|Categoria do MFC|Descrição|
|------------------|-----------------|
|`traceAppMsg`|Uso geral, as mensagens do MFC. Sempre recomendado.|
|`traceDumpContext`|Mensagens do [CDumpContext](../../mfc/reference/cdumpcontext-class.md).|
|`traceWinMsg`|Mensagens de código de manipulação de mensagens do MFC.|
|`traceMemory`|Mensagens de código de gerenciamento de memória do MFC.|
|`traceCmdRouting`|Código de roteamento de comando de mensagens do Windows do MFC.|
|`traceHtml`|Mensagens de suporte de caixa de diálogo do MFC DHTML.|
|`traceSocket`|Mensagens de suporte de soquete do MFC.|
|`traceOle`|Mensagens de suporte OLE do MFC.|
|`traceDatabase`|Mensagens do suporte de banco de dados do MFC.|
|`traceInternet`|Suportam a mensagens da Internet do MFC.|

Para declarar uma categoria de rastreamento personalizada, declare uma instância global do `CTraceCategory` classe da seguinte maneira:

[!code-cpp[NVC_ATL_Utilities#109](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_3.cpp)]

O nome da categoria, MY_CATEGORY neste exemplo, é o nome que você especificar para o *categoria* parâmetro. O primeiro parâmetro é o nome da categoria que será exibido na ferramenta de rastreamento de ATL/MFC. O segundo parâmetro é o nível de rastreamento padrão. Esse parâmetro é opcional e o nível de rastreamento padrão é 0.

Para usar uma categoria definida pelo usuário:

[!code-cpp[NVC_ATL_Utilities#110](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_4.cpp)]

Para especificar que você deseja filtrar as mensagens de rastreamento, inserir definições para essas macros em Stdafx. h antes do `#include <atlbase.h>` instrução.

Como alternativa, você pode definir o filtro em diretivas de pré-processador na **páginas de propriedade** caixa de diálogo. Clique o **pré-processador** guia e, em seguida, insira global para o **definições de pré-processador** caixa de edição.

Atlbase. h contém as definições padrão de macros ATLTRACE2 e essas definições serão usadas se você não definir esses símbolos antes atlbase. h é processado.

Em compilações de versão, ATLTRACE2 é compilado em `(void) 0`.

ATLTRACE2 limita o conteúdo da cadeia de caracteres a serem enviados para o dispositivo de despejo para não mais do que 1023 caracteres, após a formatação.

ATLTRACE e ATLTRACE2 têm o mesmo comportamento, ATLTRACE é incluído para compatibilidade com versões anteriores.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#111](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_5.cpp)]

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)<br/>
[Funções globais de relatório de erros e depuração](../../atl/reference/debugging-and-error-reporting-global-functions.md)
