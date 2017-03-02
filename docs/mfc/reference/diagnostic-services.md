---
title: "Serviços de diagnóstico | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros
dev_langs:
- C++
helpviewer_keywords:
- diagnosis, diagnostic services
- diagnostic macros, list of general MFC
- services, diagnostic
- MFC, diagnostic services
- general diagnostic functions and variables
- diagnostics, diagnostic functions and variables
- diagnostics, list of general MFC
- diagnosis, diagnostic functions and variables
- diagnosis, list of general MFC
- general diagnostic macros in MFC
- diagnostic macros
- diagnostic services
- object diagnostic functions in MFC
- diagnostics, diagnostic services
- diagnostic functions and variables
ms.assetid: 8d78454f-9fae-49c2-88c9-d3fabd5393e8
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 17a158366f94d27b7a46917282425d652e6b9042
ms.openlocfilehash: 86fe366a4d7863fb9339b7b5a9f880103876de33
ms.lasthandoff: 02/25/2017

---
# <a name="diagnostic-services"></a>Serviços de diagnóstico
A biblioteca Microsoft Foundation Class fornece muitos serviços de diagnóstico que tornam seus programas mais fácil de depuração. Esses serviços de diagnóstico incluem macros e funções globais que permitem que você controle a memória do seu programa alocações, despejar o conteúdo de objetos em tempo de execução e imprimir mensagens de depuração em tempo de execução. As macros e funções globais para serviços de diagnóstico são agrupadas nas seguintes categorias:  
  
-   Macros de diagnóstico gerais  
  
-   Funções de diagnóstico gerais e variáveis  
  
-   Funções de diagnóstico de objeto  
  
 Essas macros e funções estão disponíveis para todas as classes derivadas de `CObject` nas versões de depuração e versão do MFC. No entanto, todos exceto `DEBUG_NEW` e **verificar** fazer nada na versão de lançamento.  
  
 Na biblioteca de depuração, todos os blocos de memória alocada estão entre colchetes com uma série de "bytes de proteção". Se esses bytes são interrompidas por uma gravação de memória errônea, as rotinas de diagnóstico podem relatar um problema. Se você incluir a linha:  
  
 [!code-cpp[NVC_MFCCObjectSample&#14;](../../mfc/codesnippet/cpp/diagnostic-services_1.cpp)]  
  
 no arquivo de implementação, todas as chamadas para **novo** armazenará o número de nome de arquivo e a linha onde ocorreu a alocação de memória. A função [CMemoryState::DumpAllObjectsSince](cmemorystate-structure.md#dumpallobjectssince) exibirá essas informações extras, permitindo que você identificar vazamentos de memória. Consulte também a classe [CDumpContext](../../mfc/reference/cdumpcontext-class.md) para obter informações adicionais sobre a saída de diagnóstico.  
  
 Além disso, a biblioteca de tempo de execução C também oferece suporte a um conjunto de funções de diagnóstico que você pode usar para depurar seus aplicativos. Para obter mais informações, consulte [rotinas de depuração](../../c-runtime-library/debug-routines.md) na referência de biblioteca de tempo de execução.  
  
### <a name="mfc-general-diagnostic-macros"></a>Macros de diagnóstico do MFC geral  
  
|||  
|-|-|  
|[ASSERT](#assert)|Imprime uma mensagem e, em seguida, anula o programa se a expressão especificada for avaliada como **FALSE** na versão de depuração da biblioteca.|  
|[ASSERT_KINDOF](#assert_kindof)|Testes de que um objeto é um objeto da classe especificada ou de uma classe derivada da classe especificada.|  
|[ASSERT_VALID](#assert_valid)|Testa a validade interna de um objeto chamando seu `AssertValid` função do membro; normalmente substituída de `CObject`.|  
|[DEBUG_NEW](#debug_new)|Fornece um número de linha e de nome de arquivo para todas as alocações de objeto no modo de depuração para ajudar a localizar vazamentos de memória.|  
|[DEBUG_ONLY](#debug_only)|Semelhante ao **ASSERT** , mas não testa o valor da expressão; útil para o código que deve ser executado somente no modo de depuração.|  
|[TRACE](#trace)|Fornece `printf`-como recurso na versão de depuração da biblioteca.|  
|[VERIFIQUE SE](#verify)|Semelhante ao **ASSERT** mas avalia a expressão na versão de lançamento da biblioteca, bem como a versão de depuração.|  
  
### <a name="mfc-general-diagnostic-variables-and-functions"></a>Funções e variáveis de diagnóstico do MFC geral  
  
|||  
|-|-|  
|[afxDump](#afxdump)|Variável global envia [CDumpContext](../../mfc/reference/cdumpcontext-class.md) informações para a janela de saída do depurador ou para o terminal de depuração.|  
|[afxMemDF](#afxmemdf)|Variável global que controla o comportamento do alocador de memória depuração.|  
|[AfxCheckError](#afxcheckerror)|Variável global usado para testar o passado **SCODE** para ver se ele é um erro e, em caso afirmativo, gerará o erro apropriado.|  
|[AfxCheckMemory](#afxcheckmemory)|Verifica que a integridade de todos os memória alocada atualmente.|  
|[AfxDump](#cdumpcontext_in_mfc_)|Se chamado no depurador, despejos de memória o estado de um objeto durante a depuração.|  
|[AfxDumpStack](#afxdumpstack)|Gere uma imagem da pilha atual. Esta função sempre está vinculada estaticamente.|  
|[AfxEnableMemoryLeakDump](#afxenablememoryleakdump)|Permite que o despejo de vazamento de memória.|  
|[AfxEnableMemoryTracking](#afxenablememorytracking)|Ativa o acompanhamento no local e fora da memória.|  
|[AfxIsMemoryBlock](#afxismemoryblock)|Verifica se um bloco de memória foi alocado corretamente.|  
|[AfxIsValidAddress](#afxisvalidaddress)|Verifica se um intervalo de endereços de memória está dentro dos limites do programa.|  
|[AfxIsValidString](#afxisvalidstring)|Determina se um ponteiro para uma cadeia de caracteres é válido.|  
|[AfxSetAllocHook](#afxsetallochook)|Permite a chamada de uma função em cada alocação de memória.|  
  
### <a name="mfc-object-diagnostic-functions"></a>Funções de diagnóstico de objeto do MFC  
  
|||  
|-|-|  
|[AfxDoForAllClasses](#afxdoforallclasses)|Executa uma função especificada em todos os `CObject`-classes que oferecem suporte a verificação de tipo de tempo de execução derivadas.|  
|[AfxDoForAllObjects](#afxdoforallobjects)|Executa uma função especificada em todos os `CObject`-objetos alocados com derivados **novo**.|  
  
##  <a name="a-nameasserta--assert"></a><a name="assert"></a>ASSERT
 Avalia seu argumento.  
  
```   
ASSERT(booleanExpression)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `booleanExpression`  
 Especifica uma expressão (incluindo valores de ponteiro) que é avaliada como zero ou 0.  
  
### <a name="remarks"></a>Comentários  
 Se o resultado for 0, a macro imprime uma mensagem de diagnóstico e anula o programa. Se a condição for diferente de zero, ele não fará nada.  
  
 A mensagem de diagnóstico tem o formato  
  
 `assertion failed in file <name> in line <num>`  
  
 onde *nome* é o nome do arquivo de origem, e *num* é o número da linha da asserção que falhou no arquivo de origem.  
  
 Na versão de lançamento do MFC, **ASSERT** não avalia a expressão e, portanto, não interromperá o programa. Se a expressão deve ser avaliada, independentemente do ambiente, use o **verificar** macro no lugar de **ASSERT**.  
  
> [!NOTE]
>  Esta função está disponível somente na versão de depuração do MFC.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities&#44;](../../mfc/codesnippet/cpp/diagnostic-services_2.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h 

##  <a name="a-nameassertkindofa--assertkindof"></a><a name="assert_kindof"></a>ASSERT_KINDOF  
 Essa macro declara que o objeto apontado é um objeto da classe especificada ou é um objeto de uma classe derivado da classe especificada.  
  
```   
ASSERT_KINDOF(classname, pobject)  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nome da classe*  
 O nome de uma `CObject`-classe derivada.  
  
 *pobject*  
 Um ponteiro para um objeto de classe.  
  
### <a name="remarks"></a>Comentários  
 O *pobject* parâmetro deve ser um ponteiro para um objeto e pode ser **const**. O objeto apontado e a classe deve suportar `CObject` informações de classe de tempo de execução. Por exemplo, para garantir que `pDocument` é um ponteiro para um objeto do `CMyDoc` classe ou qualquer um de seus derivados, você pode codificar:  
  
 [!code-cpp[NVC_MFCDocView&#194;](../../mfc/codesnippet/cpp/diagnostic-services_3.cpp)]  
  
 Usando o `ASSERT_KINDOF` macro é exatamente a mesma codificação:  
  
 [!code-cpp[NVC_MFCDocView&#195;](../../mfc/codesnippet/cpp/diagnostic-services_4.cpp)]  
  
 Essa função funciona somente para classes declaradas com o [DECLARE_DYNAMIC] (run-tempo-objeto-modelo-services.md #declare_dynamic ou [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) macro.  
  
> [!NOTE]
>  Esta função está disponível somente na versão de depuração do MFC.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h 

##  <a name="a-nameassertvalida--assertvalid"></a><a name="assert_valid"></a>ASSERT_VALID  
 Use para testar suas suposições sobre a validade do estado interno de um objeto.  
  
```   
ASSERT_VALID(pObject)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `pObject`  
 Especifica um objeto de uma classe derivada de `CObject` que tem uma versão de substituição do `AssertValid` função de membro.  
  
### <a name="remarks"></a>Comentários  
 `ASSERT_VALID`chamadas de `AssertValid` função de membro do objeto passado como seu argumento.  
  
 Na versão de lançamento do MFC, `ASSERT_VALID` não faz nada. Na versão de depuração, ele valida o ponteiro, verificações em relação a **nulo**e chama o objeto próprio `AssertValid` funções de membro. Se qualquer um desses testes falhar, uma mensagem de alerta é exibida da mesma maneira como [ASSERT](#assert).  
  
> [!NOTE]
>  Esta função está disponível somente na versão de depuração do MFC.  
  
 Para obter mais informações e exemplos, consulte [Depurando aplicativos MFC](/visualstudio/debugger/mfc-debugging-techniques).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[19 NVC_MFCCObjectSample](../../mfc/codesnippet/cpp/diagnostic-services_5.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h

##  <a name="a-namedebugnewa--debugnew"></a><a name="debug_new"></a>DEBUG_NEW  
 Ajuda a localizar vazamentos de memória.  
  
```   
#define  new DEBUG_NEW   
```  
  
### <a name="remarks"></a>Comentários  
 Você pode usar `DEBUG_NEW` em qualquer lugar no programa que você normalmente usaria o **novo** operador para alocar o armazenamento de heap.  
  
 No modo de depuração (quando o **Debug** símbolo é definido), `DEBUG_NEW` mantém controle sobre o número de nome de arquivo e de linha para cada objeto que aloca. Em seguida, quando você usa o [CMemoryState::DumpAllObjectsSince](cmemorystate-structure.md#dumpallobjectssince) função de membro, cada objeto alocado com `DEBUG_NEW` é mostrada com o número de linha e de nome de arquivo onde foi alocado.  
  
 Para usar `DEBUG_NEW`, insira a seguinte diretiva de seus arquivos de origem:  
  
 [!code-cpp[NVC_MFCCObjectSample&#14;](../../mfc/codesnippet/cpp/diagnostic-services_1.cpp)]  
  
 Depois de inserir essa diretiva, o pré-processador irá inserir `DEBUG_NEW` onde quer que você use **nova**, e MFC faz o resto. Quando você compila uma versão de lançamento do seu programa, `DEBUG_NEW` resolve para um simples **novo** operação e as informações de número de nome de arquivo e a linha não são gerados.  
  
> [!NOTE]
>  Nas versões anteriores do MFC (4.1 e anterior) é necessária para colocar o `#define` instrução após todas as instruções que chamou o `IMPLEMENT_DYNCREATE` ou `IMPLEMENT_SERIAL` macros. Isso não é mais necessário.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h

##  <a name="a-namedebugonlya--debugonly"></a><a name="debug_only"></a>DEBUG_ONLY  
 No modo de depuração (quando o **Debug** símbolo é definido), `DEBUG_ONLY` avalia seu argumento.  
  
```   
DEBUG_ONLY(expression)   
```  
  
### <a name="remarks"></a>Comentários  
 Em uma compilação de versão, **DEBUG_ONLY** não avalia seu argumento. Isso é útil quando você tem código que deve ser executado somente em compilações de depuração.  
  
 O `DEBUG_ONLY` macro é equivalente ao redor *expressão* com **Debug #ifdef** e `#endif`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[32 NVC_MFC_Utilities](../../mfc/codesnippet/cpp/diagnostic-services_6.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h

##  <a name="a-nametracea--trace"></a><a name="trace"></a>RASTREAMENTO  
 Envia a cadeia especificada para o depurador do aplicativo atual.  
  
```   
TRACE(exp)  
TRACE(DWORD  category,  UINT  level, LPCSTR lpszFormat, ...)   
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [ATLTRACE2](http://msdn.microsoft.com/library/467ff555-e7a5-4f94-bdd9-50ee27ab9986) para obter uma descrição de **rastreamento**. **RASTREAMENTO** e `ATLTRACE2` têm o mesmo comportamento.  
  
 Na versão de depuração do MFC, essa macro envia a cadeia especificada para o depurador do aplicativo atual. Em uma compilação de versão, essa macro é compilado em nada (nenhum código é gerado em todos os).  
  
 Para obter mais informações, consulte [Depurando aplicativos MFC](/visualstudio/debugger/mfc-debugging-techniques).  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h

##  <a name="a-nameverifya--verify"></a><a name="verify"></a>VERIFIQUE SE  
 Na versão de depuração do MFC, avalia seu argumento.  
  
```   
VERIFY(booleanExpression)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `booleanExpression`  
 Especifica uma expressão (incluindo valores de ponteiro) que é avaliada como zero ou 0.  
  
### <a name="remarks"></a>Comentários  
 Se o resultado for 0, a macro imprime uma mensagem de diagnóstico e interrompe o programa. Se a condição for diferente de zero, ele não fará nada.  
  
 A mensagem de diagnóstico tem o formato  
  
 `assertion failed in file <name> in line <num>`  
  
 onde *nome* é o nome do arquivo de origem e *num* é o número da linha da asserção que falhou no arquivo de origem.  
  
 Na versão de lançamento do MFC, **verificar** avalia a expressão, mas não imprimir ou interrompa o programa. Por exemplo, se a expressão for uma chamada de função, a chamada será feita.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#198;](../../mfc/codesnippet/cpp/diagnostic-services_7.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h

##  <a name="a-namecdumpcontextinmfca--afxdump-cdumpcontext-in-mfc"></a><a name="cdumpcontext_in_mfc_"></a>afxDump (CDumpContext em MFC)  
 Fornece o recurso básico de despejo de objeto em seu aplicativo.  
  
```   
CDumpContext  afxDump;   
```  
  
### <a name="remarks"></a>Comentários  
 `afxDump`é um modelo predefinido [CDumpContext](../../mfc/reference/cdumpcontext-class.md) objeto que permite que você envie `CDumpContext` informações para a janela de saída do depurador ou um terminal de depuração. Normalmente, você fornece `afxDump` como um parâmetro para `CObject::Dump`.  
  
 No Windows NT e todas as versões do Windows, `afxDump` saída é enviada para a janela de depuração de saída do Visual C++ quando você depurar seu aplicativo.  
  
 Essa variável é definida somente na versão de depuração do MFC. Para obter mais informações sobre `afxDump`, consulte [Depurando aplicativos MFC](/visualstudio/debugger/mfc-debugging-techniques).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities&#23;](../../mfc/codesnippet/cpp/diagnostic-services_8.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h

##  <a name="a-nameafxmemdfa--afxmemdf"></a><a name="afxmemdf"></a>afxMemDF  
 Essa variável pode ser acessado em um depurador ou o seu programa e permite ajustar o diagnóstico de alocação.  
  
```   
int  afxMemDF;  
```  
  
### <a name="remarks"></a>Comentários  
 `afxMemDF`pode ter os seguintes valores conforme especificado pela enumeração `afxMemDF`:  
  
- **allocMemDF** ativa o alocador de depuração (configuração padrão na biblioteca de depuração).  
  
- **delayFreeMemDF** atrasa a liberação de memória. Enquanto seu programa libera um bloco de memória, o alocador não retorna se a memória para o sistema operacional subjacente. Isso colocará o estresse de memória máxima em seu programa.  
  
- **checkAlwaysMemDF** chamadas `AfxCheckMemory` sempre que a memória é alocada ou liberada. Isso reduzirá significativamente desalocações e alocações de memória.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[30 NVC_MFC_Utilities](../../mfc/codesnippet/cpp/diagnostic-services_9.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h

##  <a name="a-nameafxcheckerrora--afxcheckerror"></a><a name="afxcheckerror"></a>AfxCheckError  
 Essa função testa transmitido **SCODE** para ver se ele é um erro.  
  
```   
void AFXAPI AfxCheckError(SCODE sc);
throw CMemoryException* 
throw COleException*  
```  
  
### <a name="remarks"></a>Comentários  
 Se for um erro, a função gera uma exceção. Se o passado `SCODE` é **E_OUTOFMEMORY**, a função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) chamando [AfxThrowMemoryException](exception-processing.md#afxthrowmemoryexception). Caso contrário, a função gera uma [COleException](../../mfc/reference/coleexception-class.md) chamando [AfxThrowOleException](exception-processing.md#afxthrowoleexception).  
  
 Essa função pode ser usada para verificar os valores de retorno de chamadas para funções OLE em seu aplicativo. Testando o valor de retorno com essa função em seu aplicativo, você pode reagir adequadamente às condições de erro com uma quantidade mínima de código.  
  
> [!NOTE]
>  Essa função tem o mesmo efeito no modo de depuração e compilações de depuração não.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[33 NVC_MFCOleContainer](../../mfc/codesnippet/cpp/diagnostic-services_10.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h

##  <a name="a-nameafxcheckmemorya--afxcheckmemory"></a><a name="afxcheckmemory"></a>AfxCheckMemory  
 Esta função valida o pool de memória livre e imprime as mensagens de erro conforme necessário.  
  
```   
BOOL  AfxCheckMemory(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se não há erros de memória. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se a função não detectar nenhum dano na memória, ele imprime nada.  
  
 Todos os blocos de memória atualmente alocados no heap são verificados, incluindo aqueles alocada por **novo** , mas não os alocada por chamadas diretas para alocadores de memória subjacente, como o `malloc` função ou o **GlobalAlloc** função do Windows. Se for encontrado qualquer bloco corrompido, uma mensagem é impresso na saída do depurador.  
  
 Se você incluir a linha  
  
 [!code-cpp[NVC_MFCCObjectSample&#14;](../../mfc/codesnippet/cpp/diagnostic-services_1.cpp)]  
  
 em um módulo de programa, as chamadas subsequentes, em seguida, para `AfxCheckMemory` mostram o número de linha e de nome de arquivo em que a memória foi alocada.  
  
> [!NOTE]
>  Se o módulo contém uma ou mais implementações de classes serializáveis, você deve colocar o `#define` linha após a última `IMPLEMENT_SERIAL` chamada de macro.  
  
 Essa função funciona apenas na versão de depuração do MFC.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCObjectSample&#26;](../../mfc/codesnippet/cpp/diagnostic-services_11.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h  
 
##  <a name="a-namemfca--afxdump-mfc"></a><a name="mfc_"></a>AfxDump (MFC)  
 Chame essa função no depurador para despejar o estado de um objeto durante a depuração.  
  
```   
void AfxDump(const CObject* pOb); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pOb`  
 Um ponteiro para um objeto de uma classe derivada de `CObject`.  
  
### <a name="remarks"></a>Comentários  
 **AfxDump** chama um objeto `Dump` função de membro e envia as informações para o local especificadas pelo `afxDump` variável. **AfxDump** está disponível somente na versão de depuração do MFC.  
  
 O código do programa não deve chamar **AfxDump**, mas em vez disso, deve chamar o `Dump` função de membro do objeto apropriado.  
  
##  <a name="a-nameafxdumpstacka--afxdumpstack"></a><a name="afxdumpstack"></a>AfxDumpStack  
 Essa função global pode ser usada para gerar uma imagem da pilha atual.  
  
```   
void AFXAPI AfxDumpStack(DWORD dwTarget = AFX_STACK_DUMP_TARGET_DEFAULT); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwTarget*  
 Indica o destino da saída de despejo. Os valores possíveis, que podem ser combinados usando OR bit a bit ( **|**) são de operador, da seguinte maneira:  
  
- **AFX_STACK_DUMP_TARGET_TRACE** envia a saída por meio do [rastreamento](#trace) macro. O **rastreamento** macro gera saída em compilações de depuração somente; ele não gera nenhuma saída em compilações de versão. Além disso, **rastreamento** podem ser redirecionados para outros destinos, além do depurador.  
  
- **AFX_STACK_DUMP_TARGET_DEFAULT** envia despejar a saída para o destino padrão. Para uma compilação de depuração, a saída vai para o **rastreamento** macro. Em uma compilação de versão, a saída vai para a área de transferência.  
  
- **AFX_STACK_DUMP_TARGET_CLIPBOARD** envia a saída apenas na área de transferência. Os dados são colocados na área de transferência como texto sem formatação usando o **CF_TEXT** formato de área de transferência.  
  
- **AFX_STACK_DUMP_TARGET_BOTH** envia a saída para a área de transferência e o **rastreamento** macro, simultaneamente.  
  
- **AFX_STACK_DUMP_TARGET_ODS** envia a saída diretamente para o depurador por meio a função Win32 **OutputDebugString()**. Essa opção gerar saída do depurador em ambos os depuração e libere compilações quando um depurador é anexado ao processo. **AFX_STACK_DUMP_TARGET_ODS** sempre atinge o depurador (se ele está conectado) e não poderá ser redirecionado.  
  
### <a name="remarks"></a>Comentários  
 O exemplo a seguir reflete uma única linha da saída gerada a partir da chamada `AfxDumpStack` de um manipulador de botão em um aplicativo de caixa de diálogo do MFC:  
  
 `=== begin AfxDumpStack output ===`  
  
 `00427D55: DUMP2\DEBUG\DUMP2.EXE! void AfxDumpStack(unsigned long) + 181 bytes`  
  
 `0040160B: DUMP2\DEBUG\DUMP2.EXE! void CDump2Dlg::OnClipboard(void) + 14 bytes`  
  
 `0044F884: DUMP2\DEBUG\DUMP2.EXE! int _AfxDispatchCmdMsg(class CCmdTarget *,`  
  
 `unsigned int,int,void ( CCmdTarget::*)(void),void *,unsigned int,struct AFX_CMDHANDLE`  
  
 `0044FF7B: DUMP2\DEBUG\DUMP2.EXE! virtual int CCmdTarget::OnCmdMsg(unsigned`  
  
 `int,int,void *,struct AFX_CMDHANDLERINFO *) + 626 bytes`  
  
 `00450C71: DUMP2\DEBUG\DUMP2.EXE! virtual int CDialog::OnCmdMsg(unsigned`  
  
 `int,int,void *,struct AFX_CMDHANDLERINFO *) + 36 bytes`  
  
 `00455B27: DUMP2\DEBUG\DUMP2.EXE! virtual int CWnd::OnCommand(unsigned`  
  
 `int,long) + 312 bytes`  
  
 `00454D3D: DUMP2\DEBUG\DUMP2.EXE! virtual int CWnd::OnWndMsg(unsigned`  
  
 `int,unsigned int,long,long *) + 83 bytes`  
  
 `00454CC0: DUMP2\DEBUG\DUMP2.EXE! virtual long CWnd::WindowProc(unsigned`  
  
 `int,unsigned int,long) + 46 bytes`  
  
 `004528D9: DUMP2\DEBUG\DUMP2.EXE! long AfxCallWndProc(class CWnd *,struct`  
  
 `HWND__ *,unsigned int,unsigned int,long) + 237 bytes`  
  
 `00452D34: DUMP2\DEBUG\DUMP2.EXE! long AfxWndProc(struct HWND__ *,unsigned`  
  
 `int,unsigned int,long) + 129 bytes`  
  
 `BFF73663: WINDOWS\SYSTEM\KERNEL32.DLL! ThunkConnect32 + 2148 bytes`  
  
 `BFF928E0: WINDOWS\SYSTEM\KERNEL32.DLL! UTUnRegister + 2492 bytes`  
  
 `=== end AfxDumpStack() output ===`  
  
 Cada linha na saída acima indica o endereço da última chamada de função, o nome de caminho completo do módulo que contém a chamada de função e o protótipo da função chamada. Se a chamada de função na pilha não acontecem no endereço exato da função, é mostrado um deslocamento de bytes.  
  
 Por exemplo, a tabela a seguir descreve a primeira linha da saída acima:  
  
|Saída|Descrição|  
|------------|-----------------|  
|`00427D55:`|O endereço de retorno da última chamada de função.|  
|`DUMP2\DEBUG\DUMP2.EXE!`|O nome de caminho completo do módulo que contém a chamada de função.|  
|`void AfxDumpStack(unsigned long)`|O protótipo de função é chamado.|  
|`+ 181 bytes`|O deslocamento em bytes do endereço do protótipo da função (nesse caso, `void AfxDumpStack(unsigned long)`) para o endereço do remetente (neste caso, `00427D55`).|  
  
 `AfxDumpStack`está disponível nas versões de depuração e nondebug das bibliotecas MFC; No entanto, a função está sempre vinculada estaticamente, mesmo quando o arquivo executável usa MFC em uma DLL compartilhada. Em implementações de biblioteca compartilhada, a função é encontrada no MFCS42. Biblioteca LIB (e suas variantes).  
  
 Para usar essa função com êxito:  
  
-   O arquivo IMAGEHLP. DLL deve estar em seu caminho. Se você não tiver essa DLL, a função exibirá uma mensagem de erro. Consulte [biblioteca de ajuda de imagem](http://msdn.microsoft.com/library/windows/desktop/ms680321) para obter informações sobre o conjunto de funções fornecida pelo IMAGEHLP.  
  
-   Os módulos que têm quadros na pilha devem incluir informações de depuração. Se eles não contêm informações de depuração, a função ainda irá gerar um rastreamento de pilha, mas o rastreamento será menos detalhado.  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h 

##  <a name="a-nameafxenablememoryleakdumpa--afxenablememoryleakdump"></a><a name="afxenablememoryleakdump"></a>AfxEnableMemoryLeakDump  
 Habilita e desabilita o despejo de vazamento de memória no `AFX_DEBUG_STATE` destruidor.  
  
```  
BOOL AFXAPI AfxEnableMemoryLeakDump(BOOL bDump);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bDump`  
 `TRUE`indica que o despejo de vazamento de memória é habilitado; `FALSE` indica o despejo de vazamento de memória está desabilitado.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor anterior para esse sinalizador.  
  
### <a name="remarks"></a>Comentários  
 Quando um aplicativo descarrega a biblioteca MFC, a biblioteca MFC verifica vazamentos de memória. Neste ponto, qualquer vazamentos de memória são relatados ao usuário por meio de **depurar** janela de [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)].  
  
 Se seu aplicativo for carregado em outra biblioteca antes da biblioteca MFC, algumas alocações de memória nessa biblioteca serão relatadas incorretamente como vazamentos de memória. Vazamentos de memória False podem fazer seu aplicativo fechar lentamente, pois a biblioteca MFC relatá-los. Nesse caso, use `AfxEnableMemoryLeakDump` para desabilitar o despejo de vazamento de memória.  
  
> [!NOTE]
>  Se você usar esse método para desativar o despejo de vazamento de memória, você não receberá relatórios de vazamentos de memória válido em seu aplicativo. Você só deve usar este método se você tiver certeza de que o relatório de vazamento de memória contém vazamentos de memória falso.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h 

##  <a name="a-nameafxenablememorytrackinga--afxenablememorytracking"></a><a name="afxenablememorytracking"></a>AfxEnableMemoryTracking  
 Normalmente, diagnóstico de memória de rastreamento está habilitado na versão de depuração do MFC.  
  
```   
BOOL AfxEnableMemoryTracking(BOOL bTrack); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *bTrack*  
 Definir esse valor como **TRUE** ativa de memória de rastreamento; **FALSE** desativa.  
  
### <a name="return-value"></a>Valor de retorno  
 A configuração anterior do sinalizador de rastreamento enable.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para desabilitar o controle de seções do código que você sabe que está alocando blocos corretamente.  
  
 Para obter mais informações sobre `AfxEnableMemoryTracking`, consulte [Depurando aplicativos MFC](/visualstudio/debugger/mfc-debugging-techniques).  
  
> [!NOTE]
>  Essa função funciona apenas na versão de depuração do MFC.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities&#24;](../../mfc/codesnippet/cpp/diagnostic-services_12.cpp)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h 

##  <a name="a-nameafxismemoryblocka--afxismemoryblock"></a><a name="afxismemoryblock"></a>AfxIsMemoryBlock  
 Testa um endereço de memória para verificar se ele representa um bloco de memória ativa atualmente alocado pela versão do diagnóstico **novo**.  
  
```   
BOOL AfxIsMemoryBlock(
    const void* p,  
    UINT nBytes,  
    LONG* plRequestNumber = NULL); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Aponta para o bloco de memória a ser testada.  
  
 `nBytes`  
 Contém a duração do bloco de memória em bytes.  
  
 `plRequestNumber`  
 Aponta para um **longo** inteiro que será preenchido com o número de sequência de alocação do bloco de memória, ou zero se ele não representa um bloco de memória ativa no momento.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o bloco de memória é alocado no momento e o tamanho correto; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ele também verifica se o tamanho especificado em relação ao tamanho alocado original. Se a função retorna zero, o número de sequência de alocação é retornado no `plRequestNumber`. Esse número representa a ordem na qual o bloco alocado em relação a todos os outros **novo** alocações.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities&#27;](../../mfc/codesnippet/cpp/diagnostic-services_13.cpp)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h 

##  <a name="a-nameafxisvalidaddressa--afxisvalidaddress"></a><a name="afxisvalidaddress"></a>AfxIsValidAddress  
 Testes de qualquer endereço de memória para garantir que ele está contido inteiramente em espaço de memória do programa.  
  
```   
BOOL AfxIsValidAddress(
    const void* lp,  
    UINT nBytes,  
    BOOL bReadWrite = TRUE); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lp`  
 Aponta para o endereço de memória a ser testada.  
  
 `nBytes`  
 Contém o número de bytes de memória a ser testada.  
  
 *bReadWrite*  
 Especifica se a memória é para leitura e gravação ( **TRUE**) ou somente leitura ( **FALSE**).  
  
### <a name="return-value"></a>Valor de retorno  
 Em compilações de depuração, diferente de zero se o bloco de memória especificado está contido em espaço de memória do programa. Caso contrário, 0.  
  
 Em compilações de depuração não diferente de zero se `lp` não for NULL; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O endereço não está restrito a blocos alocados por **novo**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities&#28;](../../mfc/codesnippet/cpp/diagnostic-services_14.cpp)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h 

##  <a name="a-nameafxisvalidstringa--afxisvalidstring"></a><a name="afxisvalidstring"></a>AfxIsValidString  
 Use esta função para determinar se um ponteiro para uma cadeia de caracteres é válido.  
  
```   
BOOL  AfxIsValidString(
    LPCSTR lpsz,  
    int nLength = -1); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpsz`  
 O ponteiro para teste.  
  
 `nLength`  
 Especifica o comprimento da cadeia de caracteres a ser testada, em bytes. Um valor de â €"1 indica que a cadeia de caracteres terminada em nulo.  
  
### <a name="return-value"></a>Valor de retorno  
 Em compilações de depuração, diferente de zero se o ponteiro especificado aponta para uma cadeia de caracteres do tamanho especificado; Caso contrário, 0.  
  
 Em compilações de depuração não diferente de zero se `lpsz` não for NULL; caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[29 NVC_MFC_Utilities](../../mfc/codesnippet/cpp/diagnostic-services_15.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h 

##  <a name="a-nameafxsetallochooka--afxsetallochook"></a><a name="afxsetallochook"></a>AfxSetAllocHook  
 Define um gancho que permite a chamada da função especificada antes de cada bloco de memória é alocado.  
  
```   
AFX_ALLOC_HOOK AfxSetAllocHook(AFX_ALLOC_HOOK pfnAllocHook); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *pfnAllocHook*  
 Especifica o nome da função a ser chamada. Consulte os comentários para o protótipo de uma função de alocação.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se você quiser permitir que a alocação; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O alocador de memória de depuração da biblioteca Microsoft Foundation Class pode chamar uma função de hook definida pelo usuário para permitir que o usuário para monitorar a alocação de memória e controlar se a alocação é permitida. Funções de gancho de alocação são com protótipo, da seguinte maneira:  
  
 **BOOL AFXAPI AllocHook( size_t** `nSize`**, BOOL** `bObject`**, LONG** `lRequestNumber` **);**  
  
 `nSize`  
 O tamanho da alocação de memória proposto.  
  
 `bObject`  
 **TRUE** se a alocação for para um `CObject`-objeto derivado; caso contrário, **FALSE**.  
  
 `lRequestNumber`  
 Número de sequência da alocação de memória.  
  
 Observe que o **AFXAPI** convenção de chamada implica que o receptor deve remover os parâmetros da pilha.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h 

##  <a name="a-nameafxdoforallclassesa--afxdoforallclasses"></a><a name="afxdoforallclasses"></a>AfxDoForAllClasses  
 Chama a função de iteração especificada para todos os serializável `CObject`-classes derivadas no espaço de memória do aplicativo.  
  
```   
void  
AFXAPI AfxDoForAllClasses(
    void (* pfn)(const CRuntimeClass* pClass, void* pContext),  
    void* pContext); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pfn`  
 Aponta para uma função de iteração a ser chamado para cada classe. Os argumentos da função são um ponteiro para um `CRuntimeClass` objeto e um ponteiro nulo para dados extras que o chamador forneça à função.  
  
 `pContext`  
 Pontos de dados opcional que o chamador pode fornecer para a função de iteração. Esse ponteiro pode ser **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Serializável `CObject`-classes derivadas são classes derivadas usando o `DECLARE_SERIAL` macro. O ponteiro é passado para `AfxDoForAllClasses` em `pContext` é passado para a função de iteração especificado toda vez que é chamado.  
  
> [!NOTE]
>  Essa função funciona apenas na versão de depuração do MFC.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#113;](../../mfc/codesnippet/cpp/diagnostic-services_16.cpp)]  
  
 [!code-cpp[NVC_MFCCollections&#114;](../../mfc/codesnippet/cpp/diagnostic-services_17.cpp)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h 

##  <a name="a-nameafxdoforallobjectsa--afxdoforallobjects"></a><a name="afxdoforallobjects"></a>AfxDoForAllObjects  
 Executa a função de iteração especificada para todos os objetos derivam de `CObject` que tenham sido alocados com **novo**.  
  
```   
void AfxDoForAllObjects(
    void (* pfn)(CObject* pObject, void* pContext),  
    void* pContext); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pfn`  
 Aponta para uma função de iteração a ser executada para cada objeto. Os argumentos da função são um ponteiro para um `CObject` e um ponteiro nulo para dados extras que o chamador forneça à função.  
  
 `pContext`  
 Pontos de dados opcional que o chamador pode fornecer para a função de iteração. Esse ponteiro pode ser **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Pilha, global, ou objetos incorporados não são enumeradas. O ponteiro é passado para `AfxDoForAllObjects` em `pContext` é passado para a função de iteração especificado toda vez que é chamado.  
  
> [!NOTE]
>  Essa função funciona apenas na versão de depuração do MFC.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#115;](../../mfc/codesnippet/cpp/diagnostic-services_18.cpp)]  
  
 [!code-cpp[NVC_MFCCollections&#116;](../../mfc/codesnippet/cpp/diagnostic-services_19.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
