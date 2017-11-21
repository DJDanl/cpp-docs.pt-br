---
title: "Macros de relatórios de erros e depuração | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atldef/ATL::_ATL_DEBUG_INTERFACES
- atldef/ATL::_ATL_DEBUG_QI
- atldef/ATL::ATLASSERT
- afx/ATL::ATLENSURE
- atltrace/ATL::ATLTRACENOTIMPL
- atltrace/ATL::ATLTRACE
dev_langs: C++
helpviewer_keywords: macros, error reporting
ms.assetid: 4da9b87f-ec5c-4a32-ab93-637780909b9d
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e14ffb58ba19c6c3c8d3e59181a045532f5cfb92
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="debugging-and-error-reporting-macros"></a>Macros de relatórios de erros e de depuração
Essas macros fornecem recursos úteis de depuração e rastreamento.  
  
|||  
|-|-|  
|[_ATL_DEBUG_INTERFACES](#_atl_debug_interfaces)|Grava a janela de saída, perdas de qualquer interface que são detectados quando `_Module.Term` é chamado.|  
|[_ATL_DEBUG_QI](#_atl_debug_qi)|Grava todas as chamadas para `QueryInterface` a janela de saída.|  
|[ATLASSERT](#atlassert)|Executa a mesma funcionalidade que o [asserte](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) macro encontrada na biblioteca de tempo de execução do C.|  
|[ATLENSURE](#atlensure)|Executa a validação de parâmetros. Chamar `AtlThrow` se necessário|  
|[ATLTRACENOTIMPL](#atltracenotimpl)|Envia uma mensagem para o dispositivo de despejo de memória que a função especificada não está implementada.|  
|[ATLTRACE](#alttrace)|Avisos de relatórios para um dispositivo de saída, como a janela de depurador, de acordo com os sinalizadores indicados e os níveis. Incluído para compatibilidade com versões anteriores.|  
|[ATLTRACE2](#atltrace2)|Avisos de relatórios para um dispositivo de saída, como a janela de depurador, de acordo com os sinalizadores indicados e os níveis.|  
  
##  <a name="_atl_debug_interfaces"></a>_ATL_DEBUG_INTERFACES  
 Defina esta macro antes de incluir os arquivos de cabeçalho do ATL para rastrear todos os `AddRef` e **versão** chama em interfaces de seus componentes para a janela de saída.  
  
```
#define _ATL_DEBUG_INTERFACES
```  
  
### <a name="remarks"></a>Comentários  
 A saída do rastreamento serão exibidos conforme mostrado abaixo:  
  
 `ATL: QIThunk - 2008         AddRef  :   Object = 0x00d81ba0   Refcount = 1   CBug - IBug`  
  
 A primeira parte de cada rastreamento sempre será `ATL: QIThunk`. Next é um valor que identifica o determinado *interface conversão* que está sendo usado. Uma conversão de interface é um objeto usado para manter uma contagem de referência e fornecer o recurso de rastreamento usado aqui. Uma nova conversão de interface é criada em cada chamada para `QueryInterface` , exceto as solicitações para o **IUnknown** interface (nesse caso, a mesma conversão é retornada sempre de acordo com as regras de identidade do COM).  
  
 Em seguida você verá `AddRef` ou **versão** indicando qual método foi chamado. Depois disso, você verá um valor que identifica o objeto cuja contagem de referência de interface foi alterada. O valor rastreado é o **isso** ponteiro do objeto.  
  
 A contagem de referência que é rastreada é a contagem de referência que conversão após `AddRef` ou **versão** foi chamado. Observe que a contagem de referência não pode corresponder a contagem de referência para o objeto. Cada conversão mantém seu próprio contagem de referência para ajudá-lo a obedecer as regras COM contagem de referência.  
  
 A parte final do informações rastreadas é o nome do objeto e a interface que sejam afetados pelo `AddRef` ou **versão** chamar.  
  
 Qualquer interface vazamentos que são detectados quando o servidor é desligado e `_Module.Term` é chamado será registrado como este:  
  
 `ATL: QIThunk - 2005         LEAK    :   Object = 0x00d81ca0   Refcount = 1   MaxRefCount = 1   CBug - IBug`  
  
 As informações aqui fornecidas mapeia diretamente para as informações fornecidas nas instruções de rastreamento anteriores, para que você possa examinar as contagens de referência durante o tempo de vida inteiro de uma conversão de interface. Além disso, você obtém uma indicação de que a contagem de referência máximo nessa conversão de interface.  
  
> [!NOTE]
> `_ATL_DEBUG_INTERFACES`pode ser usado em compilações para venda.  
  
##  <a name="_atl_debug_qi"></a>_ATL_DEBUG_QI  
 Grava todas as chamadas para `QueryInterface` a janela de saída.  
  
```
#define _ATL_DEBUG_QI
```  
  
### <a name="remarks"></a>Comentários  
 Se uma chamada para `QueryInterface` falhou, a janela Saída exibirá:  
  
 *nome da interface* - `failed`  
  
##  <a name="atlassert"></a>ATLASSERT  
 O `ATLASSERT` macro executa a mesma funcionalidade que o [asserte](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) macro encontrada na biblioteca de tempo de execução do C.  
  
```
ATLASSERT(booleanExpression);
```  
  
### <a name="parameters"></a>Parâmetros  
 `booleanExpression`  
 Expressão (inclusive ponteiros) que é avaliada como zero ou igual a 0.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, `ATLASSERT` avalia `booleanExpression` e gera um relatório de depuração quando o resultado é false.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldef.h  
    
##  <a name="atlensure"></a>ATLENSURE  
 Essa macro é usada para validar os parâmetros passados para uma função.  
  
```
ATLENSURE(booleanExpression);
ATLENSURE_THROW(booleanExpression, hr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `booleanExpression`  
 Especifica uma expressão booleana a ser testada.  
  
 `hr`  
 Especifica um código de erro para retornar.  
  
### <a name="remarks"></a>Comentários  
 Essas macros fornecem um mecanismo para detectar e notificar o usuário de uso de parâmetro incorreto.  
  
 As chamadas de macro `ATLASSERT` e se a condição de falha chamadas `AtlThrow`.  
  
 No **ATLENSURE** caso, `AtlThrow` é chamado com E_FAIL.  
  
 No **ATLENSURE_THROW** caso, `AtlThrow` é chamado com o HRESULT especificado.  
  
 A diferença entre **ATLENSURE** e `ATLASSERT` é que **ATLENSURE** lança uma exceção na versão cria, bem como em compilações de depuração.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#108](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_1.cpp)]  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX  

##  <a name="atltracenotimpl"></a>ATLTRACENOTIMPL  
 Em compilações de depuração da ATL, envia a cadeia de caracteres " `funcname` não implementado" para o dispositivo de despejo e o retorna **E_NOTIMPL**.  
  
```
ATLTRACENOTIMPL(funcname);
```  
  
### <a name="parameters"></a>Parâmetros  
 `funcname`  
 [in] Uma cadeia de caracteres que contém o nome da função que não está implementado.  
  
### <a name="remarks"></a>Comentários  
 Nas compilações de lançamento, simplesmente retorna **E_NOTIMPL**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#127](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_2.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atltrace.h 

##  <a name="atltrace"></a>ATLTRACE
 Avisos de relatórios para um dispositivo de saída, como a janela de depurador, de acordo com os sinalizadores indicados e os níveis. Incluído para compatibilidade com versões anteriores.  
  
```
ATLTRACE(exp);

ATLTRACE(  
    DWORD category,
    UINT  level,
    LPCSTR lpszFormat, ...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `exp`  
 [in] A cadeia de caracteres e variáveis para enviar para a janela de saída do Visual C++ ou qualquer aplicativo que intercepta essas mensagens.  
  
 `category`  
 [in] Tipo de evento ou método no qual a relatório. Consulte os comentários para obter uma lista de categorias.  
  
 `level`  
 [in] O nível de rastreamento para o relatório. Consulte os comentários para obter detalhes.  
  
 `lpszFormat`  
 [in] A cadeia de caracteres formatada para enviar para o dispositivo de despejo.  
  
### <a name="remarks"></a>Comentários  
 Consulte [ATLTRACE2](#atltrace2) para obter uma descrição de **ATLTRACE**. **ATLTRACE** e `ATLTRACE2` têm o mesmo comportamento, **ATLTRACE** é incluído para compatibilidade com versões anteriores.  
  
##  <a name="atltrace2"></a>ATLTRACE2  
 Avisos de relatórios para um dispositivo de saída, como a janela de depurador, de acordo com os sinalizadores indicados e os níveis.  
  
```
ATLTRACE2(exp);

ATLTRACE2(
    DWORD category,
    UINT level,
    LPCSTRlpszFormat,  ...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `exp`  
 [in] A cadeia de caracteres para enviar para a janela de saída do Visual C++ ou qualquer aplicativo que intercepta essas mensagens.  
  
 `category`  
 [in] Tipo de evento ou método no qual a relatório. Consulte os comentários para obter uma lista de categorias.  
  
 `level`  
 [in] O nível de rastreamento para o relatório. Consulte os comentários para obter detalhes.  
  
 `lpszFormat`  
 [in] O `printf`-estilo de cadeia de caracteres de formato a ser usado para criar uma cadeia de caracteres para enviar para o dispositivo de despejo.  
  
### <a name="remarks"></a>Comentários  
 A forma abreviada `ATLTRACE2` grava uma cadeia de caracteres para o depurador da janela Saída. A segunda forma de `ATLTRACE2` também grava a saída para a janela de saída do depurador, mas está sujeita às configurações da ferramenta de rastreamento do ATL/MFC (consulte [ATLTraceTool exemplo](../../visual-cpp-samples.md)). Por exemplo, se você definir `level` 4 e a ferramenta de rastreamento do ATL/MFC para o nível 0, você não verá a mensagem. *nível de* pode ser 0, 1, 2, 3 ou 4. O padrão, 0, informa apenas os problemas mais sérios.  
  
 O `category` listas de parâmetros para definir os sinalizadores de rastreamento. Esses sinalizadores correspondem aos tipos de métodos para os quais você deseja relatar. As tabelas a seguir listam os sinalizadores de rastreamento válidas que você pode usar para o `category` parâmetro.  
  
### <a name="atl-trace-flags"></a>Sinalizadores de rastreamento do ATL  
  
|Categoria do ATL|Descrição|  
|------------------|-----------------|  
|`atlTraceGeneral`|Relatórios em todos os aplicativos de ATL. O padrão.|  
|`atlTraceCOM`|Relatórios sobre os métodos.|  
|`atlTraceQI`|Relatórios em chamadas de QueryInterface.|  
|`atlTraceRegistrar`|Relatórios sobre o registro de objetos.|  
|`atlTraceRefcount`|Relatórios sobre como alterar a contagem de referência.|  
|`atlTraceWindowing`|Relatórios sobre os métodos do windows; Por exemplo, relatórios de uma ID de mapa de mensagem inválido|  
|`atlTraceControls`|Relatórios em controles. Por exemplo, relatórios quando sua janela ou um controle é destruída.|  
|`atlTraceHosting`|Relatórios de hospedagem de mensagens. Por exemplo, informa quando um cliente em um contêiner é ativado.|  
|`atlTraceDBClient`|Relatórios sobre o modelo de consumidor do OLE DB. Por exemplo, quando uma chamada para GetData falhar, a saída pode conter o HRESULT.|  
|`atlTraceDBProvider`|Relatórios sobre o modelo de provedor do OLE DB. Por exemplo, informa se Falha na criação de uma coluna.|  
|`atlTraceSnapin`|Relatórios de aplicativos do snap-in do MMC.|  
|`atlTraceNotImpl`|Informa que a função indicada não é implementada.|  
|**atlTraceAllocation**|Mensagens de relatórios impressas pela memória ferramentas de depuração em atldbgmem.h.|  
  
### <a name="mfc-trace-flags"></a>Sinalizadores de rastreamento do MFC  
  
|Categoria do MFC|Descrição|  
|------------------|-----------------|  
|**traceAppMsg**|Uso geral, as mensagens do MFC. Sempre recomendado.|  
|**traceDumpContext**|Mensagens de [CDumpContext](../../mfc/reference/cdumpcontext-class.md).|  
|**traceWinMsg**|Mensagens de código de tratamento de mensagens do MFC.|  
|**traceMemory**|Mensagens de código de gerenciamento de memória do MFC.|  
|**traceCmdRouting**|Código de roteamento de comando de mensagens do Windows do MFC.|  
|**traceHtml**|Mensagens do suporte a caixa de diálogo do MFC DHTML.|  
|**traceSocket**|Mensagens do suporte de soquete do MFC.|  
|**traceOle**|Mensagens do suporte OLE do MFC.|  
|**traceDatabase**|Mensagens do suporte de banco de dados do MFC.|  
|**traceInternet**|Suportam a mensagens da Internet do MFC.|  
  
 Para declarar uma categoria de rastreamento personalizada, declarar uma instância global do `CTraceCategory` classe da seguinte maneira:  
  
 [!code-cpp[NVC_ATL_Utilities#109](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_3.cpp)]  
  
 O nome da categoria, `MY_CATEGORY` neste exemplo, é o nome que você especificar para o `category` parâmetro. O primeiro parâmetro é o nome da categoria que aparecerá na ferramenta de rastreamento do ATL/MFC. O segundo parâmetro é o nível de rastreamento padrão. Esse parâmetro é opcional e o nível de rastreamento padrão é 0.  
  
 Para usar uma categoria definida pelo usuário:  
  
 [!code-cpp[NVC_ATL_Utilities#110](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_4.cpp)]  
  
 Para especificar que você deseja filtrar as mensagens de rastreamento, inserir definições para essas macros Stdafx. h antes do `#include <atlbase.h>` instrução.  
  
 Como alternativa, você pode definir o filtro em diretivas de pré-processador no **páginas de propriedade** caixa de diálogo. Clique no **pré-processador** guia e, em seguida, inserir global para o **definições de pré-processador** caixa de edição.  
  
 Atlbase contém definições de padrão da `ATLTRACE2` macros e essas definições serão usadas se você não definir esses símbolos antes atlbase é processado.  
  
 Nas compilações de lançamento, `ATLTRACE2` é compilado em `(void) 0`.  
  
 `ATLTRACE2`limita o conteúdo da cadeia de caracteres a ser enviada para o dispositivo de despejo para não mais de 1.023 caracteres, após a formatação.  
  
 **ATLTRACE** e `ATLTRACE2` têm o mesmo comportamento, **ATLTRACE** é incluído para compatibilidade com versões anteriores.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#111](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_5.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)   
 [Funções globais de relatório de erros e depuração](../../atl/reference/debugging-and-error-reporting-global-functions.md)
