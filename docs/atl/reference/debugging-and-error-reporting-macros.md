---
title: "Macros de relatórios de erros e depuração | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- macros, error reporting
ms.assetid: 4da9b87f-ec5c-4a32-ab93-637780909b9d
caps.latest.revision: 18
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 112b43c325d4b73d2cc15ba41d9aac255c74da8a
ms.lasthandoff: 02/25/2017

---
# <a name="debugging-and-error-reporting-macros"></a>Macros de relatórios de erros e depuração
Essas macros fornecem recursos úteis de depuração e rastreamento.  
  
|||  
|-|-|  
|[_ATL_DEBUG_INTERFACES](#_atl_debug_interfaces)|Grava na janela de saída, perdas de qualquer interface que são detectados quando `_Module.Term` é chamado.|  
|[_ATL_DEBUG_QI](#_atl_debug_qi)|Grava todas as chamadas para `QueryInterface` na janela Saída.|  
|[ATLASSERT](#atlassert)|Executa a mesma funcionalidade que o [asserte](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) macro encontrada na biblioteca de tempo de execução C.|  
|[ATLENSURE](#atlensure)|Executa a validação de parâmetros. Chamar `AtlThrow` se necessário|  
|[ATLTRACENOTIMPL](#atltracenotimpl)|Envia uma mensagem para o dispositivo de despejo que a função especificada não está implementada.|  
|[ATLTRACE](http://msdn.microsoft.com/library/c796baa5-e2b9-4814-a27d-d800590b102e)|Avisos de relatórios para um dispositivo de saída, como a janela do depurador, de acordo com os sinalizadores indicados e níveis. Incluído para compatibilidade com versões anteriores.|  
|[ATLTRACE2](#atltrace2)|Avisos de relatórios para um dispositivo de saída, como a janela do depurador, de acordo com os sinalizadores indicados e níveis.|  
  
##  <a name="a-nameatldebuginterfacesa--atldebuginterfaces"></a><a name="_atl_debug_interfaces"></a>_ATL_DEBUG_INTERFACES  
 Definir esta macro antes de incluir quaisquer arquivos de cabeçalho do ATL para rastrear todos `AddRef` e **versão** chama nas interfaces dos componentes na janela Saída.  
  
```
#define _ATL_DEBUG_INTERFACES
```  
  
### <a name="remarks"></a>Comentários  
 A saída de rastreamento serão exibidos conforme mostrado abaixo:  
  
 `ATL: QIThunk - 2008         AddRef  :   Object = 0x00d81ba0   Refcount = 1   CBug - IBug`  
  
 A primeira parte de cada rastreamento sempre será `ATL: QIThunk`. Em seguida é um valor que identifica o particular *conversão de interface* que está sendo usado. Conversão de uma interface é um objeto usado para manter uma contagem de referência e fornecem a capacidade de rastreamento usada aqui. Uma nova conversão de interface é criada em cada chamada de `QueryInterface` , exceto as solicitações para o **IUnknown** interface (nesse caso, a mesma conversão é retornada sempre em conformidade com regras de identidade do COM).  
  
 Em seguida você verá `AddRef` ou **versão** indicando que o método foi chamado. Depois disso, você verá um valor que identifica o objeto cuja contagem de referência de interface foi alterada. O valor rastreado é o **isso** ponteiro do objeto.  
  
 A contagem de referência que é rastreada é a contagem de referência que conversão após `AddRef` ou **versão** foi chamado. Observe que a contagem de referência não pode corresponder a contagem de referência para o objeto. Cada conversão mantém seu próprio contagem de referência para ajudá-lo a estar totalmente em conformidade com regras de contagem de referência do COM.  
  
 A parte final do rastreamento de informações é o nome do objeto e a interface afetada pelo `AddRef` ou **versão** chamar.  
  
 Qualquer interface vazamentos detectados quando o servidor é desligado e `_Module.Term` é chamado será registrado como este:  
  
 `ATL: QIThunk - 2005         LEAK    :   Object = 0x00d81ca0   Refcount = 1   MaxRefCount = 1   CBug - IBug`  
  
 As informações aqui fornecidas mapeia diretamente para as informações fornecidas nas instruções de rastreamento anterior, para que você possa examinar a referência de conta em todo o tempo de vida inteiro de uma conversão de interface. Além disso, você recebe uma indicação da contagem de referência máximo na conversão dessa interface.  
  
> [!NOTE]
> `_ATL_DEBUG_INTERFACES`pode ser usado em compilações para venda.  
  
##  <a name="a-nameatldebugqia--atldebugqi"></a><a name="_atl_debug_qi"></a>_ATL_DEBUG_QI  
 Grava todas as chamadas para `QueryInterface` na janela Saída.  
  
```
#define _ATL_DEBUG_QI
```  
  
### <a name="remarks"></a>Comentários  
 Se uma chamada para `QueryInterface` falhou, a janela de saída será exibida:  
  
 *nome da interface* - `failed`  
  
##  <a name="a-nameatlasserta--atlassert"></a><a name="atlassert"></a>ATLASSERT  
 O `ATLASSERT` macro executa a mesma funcionalidade que o [asserte](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) macro encontrada na biblioteca de tempo de execução C.  
  
```
ATLASSERT(booleanExpression);
```  
  
### <a name="parameters"></a>Parâmetros  
 `booleanExpression`  
 Expressão (incluindo ponteiros) que é avaliada como zero ou 0.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, `ATLASSERT` avalia `booleanExpression` e gera um relatório de depuração quando o resultado é false.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldef.h  
    
##  <a name="a-nameatlensurea--atlensure"></a><a name="atlensure"></a>ATLENSURE  
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
 Essas macros fornecem um mecanismo para detectar e notificar o usuário sobre o uso do parâmetro incorreto.  
  
 As chamadas macro `ATLASSERT` e se a condição falhar chamadas `AtlThrow`.  
  
 No **ATLENSURE** caso, `AtlThrow` é chamado com E_FAIL.  
  
 No **ATLENSURE_THROW** caso, `AtlThrow` é chamado com o HRESULT especificado.  
  
 A diferença entre **ATLENSURE** e `ATLASSERT` que **ATLENSURE** lança uma exceção na versão compilações, bem como em compilações de depuração.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities&#108;](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_1.cpp)]  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h  

##  <a name="a-nameatltracenotimpla--atltracenotimpl"></a><a name="atltracenotimpl"></a>ATLTRACENOTIMPL  
 Em compilações de depuração da ATL, envia a cadeia de caracteres " `funcname` não implementado" para o dispositivo de despejo e o retorna **E_NOTIMPL**.  
  
```
ATLTRACENOTIMPL(funcname);
```  
  
### <a name="parameters"></a>Parâmetros  
 `funcname`  
 [in] Uma cadeia de caracteres que contém o nome da função que não está implementada.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de versão, simplesmente retorna **E_NOTIMPL**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities&#127;](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_2.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atltrace.h 

##  <a name="a-nameatla--atltrace"></a><a name="atl_"></a>ATLTRACE
 Avisos de relatórios para um dispositivo de saída, como a janela do depurador, de acordo com os sinalizadores indicados e níveis. Incluído para compatibilidade com versões anteriores.  
  
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
 [in] Tipo de evento ou método no qual ao relatório. Consulte os comentários para obter uma lista de categorias.  
  
 `level`  
 [in] O nível de rastreamento para o relatório. Consulte os comentários para obter detalhes.  
  
 `lpszFormat`  
 [in] Cadeia de caracteres formatada para enviar para o dispositivo de despejo.  
  
### <a name="remarks"></a>Comentários  
 Consulte [ATLTRACE2](#atltrace2) para obter uma descrição de **ATLTRACE**. **ATLTRACE** e `ATLTRACE2` têm o mesmo comportamento, **ATLTRACE** é incluído para compatibilidade com versões anteriores.  
  
##  <a name="a-nameatltrace2a--atltrace2"></a><a name="atltrace2"></a>ATLTRACE2  
 Avisos de relatórios para um dispositivo de saída, como a janela do depurador, de acordo com os sinalizadores indicados e níveis.  
  
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
 [in] Tipo de evento ou método no qual ao relatório. Consulte os comentários para obter uma lista de categorias.  
  
 `level`  
 [in] O nível de rastreamento para o relatório. Consulte os comentários para obter detalhes.  
  
 `lpszFormat`  
 [in] O `printf`-cadeia de caracteres de formato usar para criar uma cadeia de caracteres para enviar para o dispositivo de despejo de estilo.  
  
### <a name="remarks"></a>Comentários  
 A forma abreviada `ATLTRACE2` grava uma cadeia de caracteres do depurador da janela Saída. A segunda forma de `ATLTRACE2` também grava a saída para a janela de saída do depurador, mas é sujeitos às configurações da ferramenta de rastreamento do ATL/MFC (consulte [ATLTraceTool exemplo](../../visual-cpp-samples.md)). Por exemplo, se você definir `level` 4 e a ferramenta de rastreamento do ATL/MFC para o nível 0, você não verá a mensagem. *nível de* pode ser 0, 1, 2, 3 ou 4. O padrão, 0, relata somente os problemas mais graves.  
  
 O `category` os sinalizadores de rastreamento para definir listas de parâmetros. Esses sinalizadores correspondem aos tipos de métodos para os quais você deseja relatar. As tabelas a seguir listam os sinalizadores de rastreamento válidas que você pode usar para o `category` parâmetro.  
  
### <a name="atl-trace-flags"></a>Sinalizadores de rastreamento do ATL  
  
|Categoria ATL|Descrição|  
|------------------|-----------------|  
|`atlTraceGeneral`|Relatórios sobre todos os aplicativos da ATL. O padrão.|  
|`atlTraceCOM`|Relatórios sobre os métodos.|  
|`atlTraceQI`|Relatórios sobre chamadas de QueryInterface.|  
|`atlTraceRegistrar`|Relatórios sobre o registro de objetos.|  
|`atlTraceRefcount`|Relatórios sobre a alteração da contagem de referência.|  
|`atlTraceWindowing`|Relatórios sobre os métodos do windows; Por exemplo, relata um ID de mapa de mensagem inválido|  
|`atlTraceControls`|Relatórios sobre controles; Por exemplo, relatórios quando um controle ou janela é destruída.|  
|`atlTraceHosting`|Relatórios de hospedagem mensagens; Por exemplo, informa quando um cliente em um contêiner é ativado.|  
|`atlTraceDBClient`|Relatórios sobre o modelo de consumidor do OLE DB. Por exemplo, quando uma chamada para GetData falhar, a saída pode conter o HRESULT.|  
|`atlTraceDBProvider`|Relatórios sobre o modelo de provedor do OLE DB; Por exemplo, informa se Falha na criação de uma coluna.|  
|`atlTraceSnapin`|Relatórios de aplicativos do snap-in MMC.|  
|`atlTraceNotImpl`|Informa que a função indicada não está implementada.|  
|**atlTraceAllocation**|Mensagens de relatórios impressas pela memória ferramentas de depuração em atldbgmem.h.|  
  
### <a name="mfc-trace-flags"></a>Sinalizadores de rastreamento do MFC  
  
|Categoria do MFC|Descrição|  
|------------------|-----------------|  
|**traceAppMsg**|Finalidade geral, as mensagens do MFC. Sempre recomendado.|  
|**traceDumpContext**|Mensagens de [CDumpContext](../../mfc/reference/cdumpcontext-class.md).|  
|**traceWinMsg**|Mensagens de código de tratamento de mensagens do MFC.|  
|**traceMemory**|Mensagens de código de gerenciamento de memória do MFC.|  
|**traceCmdRouting**|Código de roteamento de comando de mensagens do Windows do MFC.|  
|**traceHtml**|Mensagens de suporte a caixa de diálogo do MFC DHTML.|  
|**traceSocket**|Mensagens de suporte de soquete do MFC.|  
|**traceOle**|Mensagens de suporte a OLE do MFC.|  
|**traceDatabase**|Mensagens de suporte de banco de dados do MFC.|  
|**traceInternet**|Suportam a mensagens da Internet do MFC.|  
  
 Para declarar uma categoria de rastreamento personalizada, declare uma instância global do `CTraceCategory` classe como a seguir:  
  
 [!code-cpp[NVC_ATL_Utilities&#109;](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_3.cpp)]  
  
 O nome da categoria, `MY_CATEGORY` neste exemplo, é o nome que você especificar para o `category` parâmetro. O primeiro parâmetro é o nome da categoria que será exibida na ferramenta de rastreamento do ATL/MFC. O segundo parâmetro é o nível de rastreamento padrão. Esse parâmetro é opcional e o nível de rastreamento padrão é 0.  
  
 Para usar uma categoria definida pelo usuário:  
  
 [!code-cpp[NVC_ATL_Utilities&#110;](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_4.cpp)]  
  
 Para especificar que você deseja filtrar as mensagens de rastreamento, inserir definições para essas macros Stdafx. h antes do `#include <atlbase.h>` instrução.  
  
 Como alternativa, você pode definir o filtro em diretivas de pré-processador no **páginas de propriedade** caixa de diálogo. Clique o **pré-processador** guia e, em seguida, insira global para o **definições de pré-processador** caixa de edição.  
  
 Atlbase. h contém as definições padrão da `ATLTRACE2` macros e essas definições serão usadas se você não definir esses símbolos antes atlbase. h é processado.  
  
 Em compilações de versão `ATLTRACE2` compila para `(void) 0`.  
  
 `ATLTRACE2`limita o conteúdo da cadeia de caracteres a ser enviada para o dispositivo de despejo para não mais de 1023 caracteres, após a formatação.  
  
 **ATLTRACE** e `ATLTRACE2` têm o mesmo comportamento, **ATLTRACE** é incluído para compatibilidade com versões anteriores.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities&#111;](../../atl/codesnippet/cpp/debugging-and-error-reporting-macros_5.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)   
 [Funções globais de relatório de erros e depuração](../../atl/reference/debugging-and-error-reporting-global-functions.md)

