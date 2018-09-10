---
title: Controle de aplicativo | Microsoft Docs
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
- application control [MFC]
ms.assetid: c1f69f15-e0fe-4515-9f36-d63d31869deb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 538a376dd14eae32864b494b7e79db1c89686b84
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44315009"
---
# <a name="application-control"></a>Controle do aplicativo
OLE requer controle substancial sobre aplicativos e seus objetos. As DLLs do sistema OLE devem ser capaz de iniciar e liberar aplicativos automaticamente, coordenar sua produção e a modificação de objetos e assim por diante. As funções neste tópico atender a esses requisitos. Além do que está sendo chamado pelo sistema OLE DLLs, essas funções, às vezes, devem ser chamadas por aplicativos também. 
  
### <a name="application-control"></a>Controle do aplicativo  
  
|||  
|-|-|  
|[AfxOleCanExitApp](#afxolecanexitapp)|Indica se o aplicativo pode terminar.|  
|[AfxOleGetMessageFilter](#afxolegetmessagefilter)|Recupera o filtro de mensagem do aplicativo atual.|  
|[AfxOleGetUserCtrl](#afxolegetuserctrl)|Recupera o sinalizador de controle de usuário atual.|  
|[AfxOleSetUserCtrl](#afxolesetuserctrl)|Define ou limpa o sinalizador de controle de usuário.|  
|[AfxOleLockApp](#afxolelockapp)|Incrementa a contagem global da estrutura do número de objetos ativos em um aplicativo.|  
|[AfxOleLockControl](#afxolelockcontrol)| Bloqueia o alocador de classe do controle especificado. |
|[AfxOleUnlockApp](#afxoleunlockapp)|Diminui a contagem da estrutura do número de objetos ativos em um aplicativo.| 
|[AfxOleUnlockControl](#afxoleunlockcontrol)| Desbloqueia o alocador de classe do controle especificado. |
|[AfxOleRegisterServerClass](#afxoleregisterserverclass)|Registra um servidor no registro do sistema OLE.|  
|[AfxOleSetEditMenu](#afxoleseteditmenu)|Implementa a interface do usuário para o *typename* objeto de comando.|  

  
##  <a name="afxolecanexitapp"></a>  AfxOleCanExitApp  
 Indica se o aplicativo pode terminar.  
  
```   
BOOL AFXAPI AfxOleCanExitApp(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o aplicativo pode sair; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um aplicativo não é encerrado se houver referências pendentes para seus objetos. As funções globais `AfxOleLockApp` e `AfxOleUnlockApp` incrementar e diminuir, respectivamente, um contador de referências a objetos do aplicativo. O aplicativo não deve terminar quando esse contador é diferente de zero. Se o contador for diferente de zero, a janela do aplicativo principal está oculto (não destruído) quando o usuário escolhe o fechamento do menu do sistema ou sair do menu arquivo. O framework chama essa função `CFrameWnd::OnClose`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAutomation#2](../../mfc/codesnippet/cpp/application-control_1.cpp)]  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h 

##  <a name="afxolegetmessagefilter"></a>  AfxOleGetMessageFilter  
 Recupera o filtro de mensagem do aplicativo atual.  
  
```   
COleMessageFilter* AFXAPI AfxOleGetMessageFilter(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o filtro de mensagem atual.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para acessar o atual `COleMessageFilter`-derivado de objeto, assim como você chamaria `AfxGetApp` para acessar o objeto de aplicativo atual.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAutomation#3](../../mfc/codesnippet/cpp/application-control_2.cpp)]  
  
 [!code-cpp[NVC_MFCAutomation#4](../../mfc/codesnippet/cpp/application-control_3.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxwin. h 

##  <a name="afxolegetuserctrl"></a>  AfxOleGetUserCtrl  
 Recupera o sinalizador de controle de usuário atual.  
  
```   
BOOL AFXAPI AfxOleGetUserCtrl(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário está no controle do aplicativo; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O usuário está no controle do aplicativo quando o usuário explicitamente abriu ou criou um novo documento. O usuário também está no controle se o aplicativo não foi iniciado pelo sistema OLE DLLs — em outras palavras, se o usuário iniciou o aplicativo com o shell do sistema.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h

##  <a name="afxolesetuserctrl"></a>  AfxOleSetUserCtrl  
 Define ou limpa o sinalizador de controle de usuário, que é explicado na referência para `AfxOleGetUserCtrl`.  
  
```  
void AFXAPI AfxOleSetUserCtrl(BOOL bUserCtrl); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *bUserCtrl*  
 Especifica se o sinalizador de controle de usuário deve ser definido ou limpo.  
  
### <a name="remarks"></a>Comentários  
 O framework chama essa função quando o usuário cria ou carrega um documento, mas não quando um documento é carregado ou criado por meio de uma ação indireta, como carregamento de um objeto inserido de um aplicativo de contêiner.  
  
 Chame essa função se outras ações em seu aplicativo devem colocar o usuário no controle do aplicativo.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h

##  <a name="afxolelockapp"></a>  AfxOleLockApp  
 Incrementa a contagem global da estrutura do número de objetos ativos no aplicativo.  
  
```   
void AFXAPI AfxOleLockApp(); 
```  
  
### <a name="remarks"></a>Comentários  
 O framework mantém uma contagem do número de objetos ativos em um aplicativo. O `AfxOleLockApp` e `AfxOleUnlockApp` funções, respectivamente, incrementar e reduzir essa contagem.  
  
 Quando o usuário tenta fechar um aplicativo que tem objetos do Active Directory — um aplicativo para o qual a contagem de objetos do Active Directory é diferente de zero, o framework oculta o aplicativo de exibição do usuário em vez de desligá-lo completamente. O `AfxOleCanExitApp` função indica se o aplicativo pode terminar.  
  
 Chamar `AfxOleLockApp` de qualquer objeto que expõe as interfaces do OLE, se ele seria indesejável para o objeto a ser destruído, enquanto ainda está sendo usado por um aplicativo cliente. Também chamar `AfxOleUnlockApp` no destruidor de qualquer objeto que chama `AfxOleLockApp` no construtor. Por padrão, `COleDocument` (e as classes derivadas) automaticamente bloquear e desbloquear o aplicativo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAutomation#5](../../mfc/codesnippet/cpp/application-control_4.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h

##  <a name="afxoleunlockapp"></a>  AfxOleUnlockApp  
 Diminui a contagem da estrutura de objetos ativos no aplicativo.  
  
```   
void AFXAPI AfxOleUnlockApp(); 
```  
  
### <a name="remarks"></a>Comentários  
 Consulte `AfxOleLockApp` para obter mais informações.  
  
 Quando o número de objetos ativos chega a zero, `AfxOleOnReleaseAllObjects` é chamado.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [AfxOleLockApp](#afxolelockapp).  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h  

 ## <a name="afxolelockcontrol"></a>AfxOleLockControl
Bloqueia o alocador de classe do controle especificado para que criado dinamicamente dados associados com o controle permanecem na memória.  
   
### <a name="syntax"></a>Sintaxe    
```
BOOL AFXAPI AfxOleLockControl(  REFCLSID clsid  );  
BOOL AFXAPI AfxOleLockControl( LPCTSTR lpszProgID );  
```
### <a name="parameters"></a>Parâmetros  
 *clsid*  
 A ID exclusiva de classe do controle.  
  
 *lpszProgID*  
 A ID exclusiva do programa do controle.  
   
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fábrica de classes do controle foi bloqueada com êxito; Caso contrário, 0.  
   
### <a name="remarks"></a>Comentários  
 Isso pode acelerar consideravelmente a exibição dos controles. Por exemplo, uma vez você criar um controle em uma caixa de diálogo e bloquear o controle com `AfxOleLockControl`, você não precisará criar e eliminá-lo novamente sempre que a caixa de diálogo é mostrada ou destruída. Se o usuário abre e fecha uma caixa de diálogo repetidamente, o bloqueio dos seus controles pode melhorar significativamente o desempenho. Quando você estiver pronto para destruir o controle, chame `AfxOleUnlockControl`.  
   
### <a name="example"></a>Exemplo  
```cpp
// Starts and locks control's (Microsoft Calendar) class factory. 
// Control will remain in memory for lifetime of
// application or until AfxOleUnlockControl() is called.

AfxOleLockControl(_T("MSCAL.Calendar"));
```
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [AfxOleUnlockControl](#afxoleunlockcontrol)
 
##  <a name="afxoleregisterserverclass"></a>  AfxOleRegisterServerClass  
 Essa função permite que você registre seu servidor no registro do sistema OLE.  
  
```   
BOOL AFXAPI AfxOleRegisterServerClass(
    REFCLSID clsid,  
    LPCTSTR lpszClassName,  
    LPCTSTR lpszShortTypeName,  
    LPCTSTR lpszLongTypeName,  
    OLE_APPTYPE nAppType = OAT_SERVER,  
    LPCTSTR* rglpszRegister = NULL,  
    LPCTSTR* rglpszOverwrite = NULL); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *clsid*  
 Referência à ID de classe OLE. do servidor  
  
 *lpszClassName*  
 Ponteiro para uma cadeia de caracteres que contém o nome de classe de objetos do servidor.  
  
 *lpszShortTypeName*  
 Ponteiro para uma cadeia de caracteres que contém o nome curto do tipo de objeto do servidor, como "Gráfico".  
  
 *lpszLongTypeName*  
 Ponteiro para uma cadeia de caracteres que contém o nome longo do tipo de objeto do servidor, como "Gráfico do Microsoft Excel 5.0".  
  
 *nAppType*  
 Um valor, obtido da enumeração OLE_APPTYPE, especificando o tipo de aplicativo do OLE. Os valores possíveis são os seguintes:  
  
- Servidor OAT_INPLACE_SERVER tem interface do usuário completo do servidor.  
  
- OAT_SERVER Server dá suporte à inserção de apenas.  
  
- Contêiner OAT_CONTAINER dá suporte a links para incorporações.  
  
- OAT_DISPATCH_OBJECT `IDispatch`-objeto capaz.  
  
 *rglpszRegister*  
 Matriz de ponteiros para cadeias de caracteres que representa as chaves e valores a serem adicionadas ao registro do sistema OLE se nenhum valor existente para as chaves forem encontrados.  
  
 *rglpszOverwrite*  
 Matriz de ponteiros para cadeias de caracteres que representa as chaves e valores a serem adicionadas ao registro do sistema OLE se o registro contém os valores existentes para as chaves de determinado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a classe de servidor for registrada com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A maioria dos aplicativos pode usar `COleTemplateServer::Register` para registrar os tipos de documento do aplicativo. Se o formato de registro do sistema do seu aplicativo não é adequado para o padrão típico, você pode usar `AfxOleRegisterServerClass` para obter mais controle.  
  
 O registro consiste em um conjunto de chaves e valores. O *rglpszRegister* e *rglpszOverwrite* argumentos são matrizes de ponteiros para cadeias de caracteres, cada uma consistindo em uma chave e um valor separado por um **nulo** caractere ( `'\0'`). Cada uma dessas cadeias de caracteres pode ter parâmetros substituíveis, cujos locais são marcados pelas sequências de caracteres *%1* por meio *%5*.  
  
 Os símbolos são preenchidos da seguinte maneira:  
  
|Símbolo|Valor|  
|------------|-----------|  
|%1|ID de classe, formatada como uma cadeia de caracteres|  
|%2|Nome da classe|  
|%3|Caminho do arquivo executável|  
|%4|Nome de tipo curto|  
|%5|Nome de tipo longo|  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h

##  <a name="afxoleseteditmenu"></a>  AfxOleSetEditMenu  
 Implementa a interface do usuário para o *typename* objeto de comando.  
  
```   
void AFXAPI AfxOleSetEditMenu(
    COleClientItem* pClient,  
    CMenu* pMenu,  
    UINT iMenuItem,  
    UINT nIDVerbMin,  
    UINT nIDVerbMax = 0,  
    UINT nIDConvert = 0); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *pClient*  
 Um ponteiro para o item OLE de cliente.  
  
 *pMenu*  
 Um ponteiro para o objeto de menu a ser atualizado.  
  
 *iMenuItem*  
 O índice do item de menu a ser atualizada.  
  
 *nIDVerbMin*  
 A ID de comando que corresponde ao verbo primário.  
  
 *nIDVerbMax*  
 A ID de comando que corresponde ao último verbo.  
  
 *nIDConvert*  
 ID do item de menu Convert.  
  
### <a name="remarks"></a>Comentários  
 Se o servidor reconhece apenas um verbo primário, torna-se o item de menu "verbo *typename* objeto" e o *nIDVerbMin* comando é enviado quando o usuário escolhe o comando. Se o servidor reconhece vários verbos e, em seguida, torna-se o item de menu " *typename* objeto" e um submenu que lista todos os verbos aparece quando o usuário escolhe o comando. Quando o usuário escolhe um verbo no submenu *nIDVerbMin* é enviado se o primeiro verbo for escolhido, *nIDVerbMin* + 1 será enviado se o segundo verbo é escolhido e assim por diante. O padrão `COleDocument` implementação controla automaticamente a esse recurso.  
  
 Você deve ter a seguinte instrução no script de recurso de aplicativo do seu cliente (. Arquivo RC):  
  
 **#include \<afxolecl.rc >**  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxole.h 

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

## <a name="afxoleunlockcontrol"></a> AfxOleUnlockControl
Desbloqueia o alocador de classe do controle especificado.  
   
### <a name="syntax"></a>Sintaxe  
```
BOOL AFXAPI AfxOleUnlockControl( REFCLSID clsid );  
BOOL AFXAPI AfxOleUnlockControl( LPCTSTR lpszProgID );  
```
### <a name="parameters"></a>Parâmetros  
 *clsid*  
 A ID exclusiva de classe do controle.  
  
 *lpszProgID*  
 A ID exclusiva do programa do controle.  
   
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fábrica de classes do controle foi desbloqueada com êxito; Caso contrário, 0.  
   
### <a name="remarks"></a>Comentários  
 Um controle estiver bloqueado com `AfxOleLockControl`, de modo que criado dinamicamente dados associados com o controle permanecem na memória. Isso pode acelerar consideravelmente a exibição do controle porque o controle não precisa ser criado e destruído cada vez que ele é exibido. Quando você estiver pronto para destruir o controle, chame `AfxOleUnlockControl`.  
   
### <a name="example"></a>Exemplo  
```cpp
// Unlock control's (Microsoft Calendar Control) class factory.

AfxOleUnlockControl(_T("MSCAL.Calendar"));

```
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)  
 [AfxOleLockControl](#afxolelockcontrol)

