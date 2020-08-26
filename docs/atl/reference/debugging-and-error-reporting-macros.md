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
ms.openlocfilehash: 2bcdfb474ee852e55bd54f1b125716e7785f28be
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833472"
---
# <a name="debugging-and-error-reporting-macros"></a>Macros de depuração e relatório de erros

Essas macros fornecem recursos úteis de depuração e rastreamento.

|Nome|Descrição|
|-|-|
|[_ATL_DEBUG_INTERFACES](#_atl_debug_interfaces)|Grava, na janela saída, qualquer vazamento de interface detectado quando `_Module.Term` é chamado.|
|[_ATL_DEBUG_QI](#_atl_debug_qi)|Grava todas as chamadas para `QueryInterface` na janela de saída.|
|[ATLASSERT](#atlassert)|Executa a mesma funcionalidade que a macro [_ASSERTE](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) encontrada na biblioteca de tempo de execução C.|
|[ATLENSURE](#atlensure)|Executa a validação de parâmetros. Chamada `AtlThrow` se necessário|
|[ATLTRACENOTIMPL](#atltracenotimpl)|Envia uma mensagem para o dispositivo de despejo que a função especificada não está implementada.|
|[ATLTRACE](#atltrace)|Relata avisos para um dispositivo de saída, como a janela do depurador, de acordo com os sinalizadores e os níveis indicados. Incluído para compatibilidade com versões anteriores.|
|[ATLTRACE2](#atltrace2)|Relata avisos para um dispositivo de saída, como a janela do depurador, de acordo com os sinalizadores e os níveis indicados.|

## <a name="_atl_debug_interfaces"></a><a name="_atl_debug_interfaces"></a> _ATL_DEBUG_INTERFACES

Defina essa macro antes de incluir qualquer arquivo de cabeçalho da ATL para rastrear todas as `AddRef` `Release` chamadas e suas interfaces de componentes para a janela de saída.

```
#define _ATL_DEBUG_INTERFACES
```

### <a name="remarks"></a>Comentários

A saída do rastreamento será exibida conforme mostrado abaixo:

`ATL: QIThunk - 2008         AddRef  :   Object = 0x00d81ba0   Refcount = 1   CBug - IBug`

A primeira parte de cada rastreamento sempre será `ATL: QIThunk` . Next é um valor que identifica a *conversão de interface* específica que está sendo usada. Uma conversão de interface é um objeto usado para manter uma contagem de referência e fornecer o recurso de rastreamento usado aqui. Uma nova conversão de interface é criada em cada chamada para `QueryInterface` , exceto para solicitações da `IUnknown` interface (nesse caso, a mesma conversão é retornada toda vez para atender às regras de identidade do com).

Em seguida, você verá `AddRef` ou `Release` indicará qual método foi chamado. Depois disso, você verá um valor que identifica o objeto cuja contagem de referência de interface foi alterada. O valor rastreado é o **`this`** ponteiro do objeto.

A contagem de referência que é rastreada é a contagem de referência nessa conversão após `AddRef` ou `Release` foi chamada. Observe que essa contagem de referência pode não corresponder à contagem de referência do objeto. Cada conversão mantém sua própria contagem de referência para ajudá-lo a cumprir totalmente as regras de contagem de referência do COM.

A parte final das informações rastreadas é o nome do objeto e a interface que está sendo afetada `AddRef` pela `Release` chamada ou.

Qualquer vazamento de interface detectado quando o servidor é desligado e `_Module.Term` chamado será registrado da seguinte maneira:

`ATL: QIThunk - 2005         LEAK    :   Object = 0x00d81ca0   Refcount = 1   MaxRefCount = 1   CBug - IBug`

As informações fornecidas aqui são mapeadas diretamente para as informações fornecidas nas instruções de rastreamento anteriores, para que você possa examinar as contagens de referência durante todo o tempo de vida de uma conversão de interface. Além disso, você obtém uma indicação da contagem de referência máxima nessa conversão de interface.

> [!NOTE]
> _ATL_DEBUG_INTERFACES pode ser usado em compilações de varejo.

## <a name="_atl_debug_qi"></a><a name="_atl_debug_qi"></a> _ATL_DEBUG_QI

Grava todas as chamadas para `QueryInterface` na janela de saída.

```
#define _ATL_DEBUG_QI
```

### <a name="remarks"></a>Comentários

Se uma chamada a `QueryInterface` falhar, a janela de saída será exibida:

*nome da interface* - `failed`

## <a name="atlassert"></a><a name="atlassert"></a> ATLASSERT

A macro ATLASSERT executa a mesma funcionalidade que a macro [_ASSERTE](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) encontrada na biblioteca de tempo de execução do C.

```
ATLASSERT(booleanExpression);
```

### <a name="parameters"></a>parâmetros

*valor booliano*<br/>
Expressão (incluindo ponteiros) que é avaliada como zero ou 0.

### <a name="remarks"></a>Comentários

Em builds de depuração, ATLASSERT avalia a *booliana* e gera um relatório de depuração quando o resultado é false.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldef. h

## <a name="atlensure"></a><a name="atlensure"></a> ATLENSURE

Essa macro é usada para validar os parâmetros passados para uma função.

```
ATLENSURE(booleanExpression);
ATLENSURE_THROW(booleanExpression, hr);
```

### <a name="parameters"></a>parâmetros

*valor booliano*<br/>
Especifica uma expressão booliana a ser testada.

*h*<br/>
Especifica um código de erro a ser retornado.

### <a name="remarks"></a>Comentários

Essas macros fornecem um mecanismo para detectar e notificar o usuário sobre o uso de parâmetro incorreto.

A macro chama ATLASSERT e se a condição falhar em chamadas `AtlThrow` .

No caso ATLENSURE, `AtlThrow` é chamado com E_FAIL.

No ATLENSURE_THROW caso, `AtlThrow` é chamado com o HRESULT especificado.

A diferença entre ATLENSURE e ATLASSERT é que o ATLENSURE gera uma exceção em compilações de versão, bem como em compilações de depuração.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#108](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="atltracenotimpl"></a><a name="atltracenotimpl"></a> ATLTRACENOTIMPL

Nas compilações de depuração da ATL, o envia a cadeia de caracteres " *FuncName* não é implementado" para o dispositivo de despejo e retorna E_NOTIMPL.

```
ATLTRACENOTIMPL(funcname);
```

### <a name="parameters"></a>parâmetros

*funcname*<br/>
no Uma cadeia de caracteres que contém o nome da função que não está implementada.

### <a name="remarks"></a>Comentários

Em builds de versão, simplesmente retorna E_NOTIMPL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#127](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_2.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLTRACE. h

## <a name="atltrace"></a><a name="atltrace"></a> ATLTRACE

Relata avisos para um dispositivo de saída, como a janela do depurador, de acordo com os sinalizadores e os níveis indicados. Incluído para compatibilidade com versões anteriores.

```
ATLTRACE(exp);

ATLTRACE(
    DWORD category,
    UINT  level,
    LPCSTR lpszFormat, ...);
```

### <a name="parameters"></a>parâmetros

*exp*<br/>
no A cadeia de caracteres e as variáveis a serem enviadas à janela de saída ou a qualquer aplicativo que intercepta essas mensagens.

*category*<br/>
no Tipo de evento ou método no qual relatar. Consulte os comentários para obter uma lista de categorias.

*nível*<br/>
no O nível de rastreamento a ser relatado. Consulte os comentários para obter detalhes.

*lpszFormat*<br/>
no A cadeia de caracteres formatada a ser enviada ao dispositivo de despejo.

### <a name="remarks"></a>Comentários

Consulte [ATLTRACE2](#atltrace2) para obter uma descrição de ATLTRACE. ATLTRACE e ATLTRACE2 têm o mesmo comportamento, ATLTRACE está incluído para compatibilidade com versões anteriores.

## <a name="atltrace2"></a><a name="atltrace2"></a> ATLTRACE2

Relata avisos para um dispositivo de saída, como a janela do depurador, de acordo com os sinalizadores e os níveis indicados.

```
ATLTRACE2(exp);

ATLTRACE2(
    DWORD category,
    UINT level,
    LPCSTR lpszFormat,  ...);
```

### <a name="parameters"></a>parâmetros

*exp*<br/>
no A cadeia de caracteres a ser enviada à janela de saída ou a qualquer aplicativo que intercepta essas mensagens.

*category*<br/>
no Tipo de evento ou método no qual relatar. Consulte os comentários para obter uma lista de categorias.

*nível*<br/>
no O nível de rastreamento a ser relatado. Consulte os comentários para obter detalhes.

*lpszFormat*<br/>
no A `printf` cadeia de caracteres de formato de estilo a ser usada para criar uma cadeia de caracteres a ser enviada ao dispositivo de despejo.

### <a name="remarks"></a>Comentários

A forma abreviada de ATLTRACE2 grava uma cadeia de caracteres na janela de saída do depurador. A segunda forma de ATLTRACE2 também grava a saída na janela de saída do depurador, mas está sujeita às configurações da ferramenta de rastreamento ATL/MFC (consulte a [amostra ATLTraceTool](../../overview/visual-cpp-samples.md)). Por exemplo, se você definir *nível* como 4 e a ferramenta de rastreamento ATL/MFC para nível 0, você não verá a mensagem. o *nível* pode ser 0, 1, 2, 3 ou 4. O padrão, 0, relata apenas os problemas mais graves.

O parâmetro *Category* lista os sinalizadores de rastreamento a serem definidos. Esses sinalizadores correspondem aos tipos de métodos para os quais você deseja relatar. As tabelas a seguir listam os sinalizadores de rastreamento válidos que você pode usar para o parâmetro *Category* .

### <a name="atl-trace-flags"></a>Sinalizadores de rastreamento da ATL

|Categoria da ATL|Descrição|
|------------------|-----------------|
|`atlTraceGeneral`|Relatórios sobre todos os aplicativos ATL. O padrão.|
|`atlTraceCOM`|Relatórios sobre métodos COM.|
|`atlTraceQI`|Relata as chamadas de QueryInterface.|
|`atlTraceRegistrar`|Relatórios sobre o registro de objetos.|
|`atlTraceRefcount`|Relatórios sobre a alteração da contagem de referência.|
|`atlTraceWindowing`|Relatórios sobre os métodos do Windows; por exemplo, relata uma ID de mapa de mensagem inválida.|
|`atlTraceControls`|Relatórios sobre controles; por exemplo, relata quando um controle ou sua janela é destruído.|
|`atlTraceHosting`|Relata mensagens de hospedagem; por exemplo, relata quando um cliente em um contêiner é ativado.|
|`atlTraceDBClient`|Relatórios sobre o modelo de consumidor OLE DB; por exemplo, quando uma chamada para GetData falha, a saída pode conter HRESULT.|
|`atlTraceDBProvider`|Relatórios sobre o modelo de provedor de OLE DB; por exemplo, relata se a criação de uma coluna falhou.|
|`atlTraceSnapin`|Relatórios do aplicativo de snap-in do MMC.|
|`atlTraceNotImpl`|Relata que a função indicada não está implementada.|
|`atlTraceAllocation`|Relata as mensagens impressas pelas ferramentas de depuração de memória em atldbgmem. h.|

### <a name="mfc-trace-flags"></a>Sinalizadores de rastreamento do MFC

|Categoria do MFC|Descrição|
|------------------|-----------------|
|`traceAppMsg`|Uso geral, mensagens do MFC. Sempre recomendado.|
|`traceDumpContext`|Mensagens de [CDumpContext](../../mfc/reference/cdumpcontext-class.md).|
|`traceWinMsg`|Mensagens do código de manipulação de mensagens do MFC.|
|`traceMemory`|Mensagens do código de gerenciamento de memória do MFC.|
|`traceCmdRouting`|Mensagens do código de roteamento de comando do Windows do MFC.|
|`traceHtml`|Mensagens do suporte à caixa de diálogo DHTML do MFC.|
|`traceSocket`|Mensagens do suporte de soquete do MFC.|
|`traceOle`|Mensagens do suporte a OLE do MFC.|
|`traceDatabase`|Mensagens do suporte a banco de dados do MFC.|
|`traceInternet`|Mensagens do suporte da Internet do MFC.|

Para declarar uma categoria de rastreamento personalizada, declare uma instância global da `CTraceCategory` classe da seguinte maneira:

[!code-cpp[NVC_ATL_Utilities#109](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_3.cpp)]

O nome da categoria, MY_CATEGORY neste exemplo, é o nome que você especifica para o parâmetro *Category* . O primeiro parâmetro é o nome da categoria que será exibido na ferramenta de rastreamento ATL/MFC. O segundo parâmetro é o nível de rastreamento padrão. Esse parâmetro é opcional e o nível de rastreamento padrão é 0.

Para usar uma categoria definida pelo usuário:

[!code-cpp[NVC_ATL_Utilities#110](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_4.cpp)]

Para especificar que você deseja filtrar as mensagens de rastreamento, insira as definições dessas macros em stdafx. h antes da `#include <atlbase.h>` instrução.

Como alternativa, você pode definir o filtro nas diretivas de pré-processador na caixa de diálogo **páginas de propriedades** . Clique na guia **pré-processador** e, em seguida, insira o global na caixa de edição definições de **pré-processador** .

Atlbase. h contém definições padrão das macros ATLTRACE2 e essas definições serão usadas se você não definir esses símbolos antes de atlbase. h ser processado.

Em builds de versão, o ATLTRACE2 é compilado para `(void) 0` .

ATLTRACE2 limita o conteúdo da cadeia de caracteres a ser enviada ao dispositivo de despejo para no máximo 1023 caracteres, após a formatação.

ATLTRACE e ATLTRACE2 têm o mesmo comportamento, ATLTRACE está incluído para compatibilidade com versões anteriores.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#111](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_5.cpp)]

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)<br/>
[Funções globais de relatório de depuração e de erro](../../atl/reference/debugging-and-error-reporting-global-functions.md)
