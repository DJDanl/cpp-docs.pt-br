---
title: Controle do aplicativo | Documentos do Microsoft
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
- application control
ms.assetid: c1f69f15-e0fe-4515-9f36-d63d31869deb
caps.latest.revision: 12
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
ms.sourcegitcommit: 17a158366f94d27b7a46917282425d652e6b9042
ms.openlocfilehash: 81eb0bcdd8c9d154f62635e7f306cefcf7a15c1b
ms.lasthandoff: 02/25/2017

---
# <a name="application-control"></a>Controle do aplicativo
A tecnologia OLE requer controle substancial sobre aplicativos e seus objetos. As DLLs do sistema OLE devem ser capaz de iniciar e libere aplicativos automaticamente, coordenar seus produção e a modificação de objetos e assim por diante. As funções neste tópico atendem a esses requisitos. Além de ser chamados por DLLs do sistema OLE, essas funções, às vezes, devem ser chamadas por aplicativos bem.  
  
### <a name="application-control"></a>Controle do aplicativo  
  
|||  
|-|-|  
|[AfxOleCanExitApp](#afxolecanexitapp)|Indica se o aplicativo pode terminar.|  
|[AfxOleGetMessageFilter](#afxolegetmessagefilter)|Recupera o filtro de mensagens do aplicativo atual.|  
|[AfxOleGetUserCtrl](#afxolegetuserctrl)|Recupera o sinalizador de controle de usuário atual.|  
|[AfxOleSetUserCtrl](#afxolesetuserctrl)|Define ou limpa o sinalizador de controle de usuário.|  
|[AfxOleLockApp](#afxolelockapp)|Incrementa a contagem global da estrutura do número de objetos ativos em um aplicativo.|  
|[AfxOleUnlockApp](#afxoleunlockapp)|Diminui a contagem da estrutura do número de objetos ativos em um aplicativo.|  
|[AfxOleRegisterServerClass](#afxoleregisterserverclass)|Registra um servidor no registro do sistema OLE.|  
|[AfxOleSetEditMenu](#afxoleseteditmenu)|Implementa a interface do usuário para o *typename* objeto de comando.|  
  
##  <a name="a-nameafxolecanexitappa--afxolecanexitapp"></a><a name="afxolecanexitapp"></a>AfxOleCanExitApp  
 Indica se o aplicativo pode terminar.  
  
```   
BOOL AFXAPI AfxOleCanExitApp(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o aplicativo pode sair; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um aplicativo não deve ser interrompido se houver referências pendentes em seus objetos. As funções globais `AfxOleLockApp` e `AfxOleUnlockApp` incrementar e diminuir, respectivamente, um contador de referências a objetos do aplicativo. O aplicativo não deve terminar quando esse contador for diferente de zero. Se o contador for diferente de zero, a janela do aplicativo principal é oculto (não destruído) quando o usuário escolhe Fechar no menu de sistema ou sair do menu arquivo. O framework chama essa função **CFrameWnd::OnClose**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAutomation n º&2;](../../mfc/codesnippet/cpp/application-control_1.cpp)]  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h 

##  <a name="a-nameafxolegetmessagefiltera--afxolegetmessagefilter"></a><a name="afxolegetmessagefilter"></a>AfxOleGetMessageFilter  
 Recupera o filtro de mensagens do aplicativo atual.  
  
```   
COleMessageFilter* AFXAPI  AfxOleGetMessageFilter(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o filtro de mensagem atual.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para acessar o atual `COleMessageFilter`-derivado de objeto, assim como você poderia chamar `AfxGetApp` para acessar o objeto de aplicativo atual.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAutomation n º&3;](../../mfc/codesnippet/cpp/application-control_2.cpp)]  
  
 [!code-cpp[NVC_MFCAutomation n º&4;](../../mfc/codesnippet/cpp/application-control_3.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxwin. h 

##  <a name="a-nameafxolegetuserctrla--afxolegetuserctrl"></a><a name="afxolegetuserctrl"></a>AfxOleGetUserCtrl  
 Recupera o sinalizador de controle de usuário atual.  
  
```   
BOOL  AFXAPI AfxOleGetUserCtrl(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário está no controle do aplicativo; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O usuário está no controle do aplicativo quando o usuário explicitamente abriu ou criou um novo documento. O usuário também está no controle se o aplicativo não foi iniciado pelo sistema OLE DLLs — em outras palavras, se o usuário iniciou o aplicativo com o shell do sistema.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h

##  <a name="a-nameafxolesetuserctrla--afxolesetuserctrl"></a><a name="afxolesetuserctrl"></a>AfxOleSetUserCtrl  
 Define ou limpa o sinalizador de controle de usuário, que é explicado na referência para `AfxOleGetUserCtrl`.  
  
```  
void  AFXAPI AfxOleSetUserCtrl(BOOL bUserCtrl); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *bUserCtrl*  
 Especifica se o sinalizador de controle de usuário deve ser definido ou limpo.  
  
### <a name="remarks"></a>Comentários  
 O framework chama essa função quando o usuário cria ou carrega um documento, mas não quando um documento for carregado ou criado por meio de uma ação indireta como o carregamento de um objeto incorporado em um aplicativo de contêiner.  
  
 Chame essa função se outras ações no seu aplicativo devem colocar o usuário no controle do aplicativo.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h

##  <a name="a-nameafxolelockappa--afxolelockapp"></a><a name="afxolelockapp"></a>AfxOleLockApp  
 Incrementa a contagem global da estrutura do número de objetos ativos no aplicativo.  
  
```   
void  AFXAPI  AfxOleLockApp(); 
```  
  
### <a name="remarks"></a>Comentários  
 O framework mantém uma contagem do número de objetos ativo em um aplicativo. O `AfxOleLockApp` e `AfxOleUnlockApp` funções, respectivamente, incrementar e diminuir essa contagem.  
  
 Quando o usuário tenta fechar um aplicativo que tenha objetos ativos — um aplicativo para o qual a contagem de objetos ativos é diferente de zero, o framework oculta a exibição do usuário em vez de desligá-lo completamente do aplicativo. O `AfxOleCanExitApp` função indica se o aplicativo pode terminar.  
  
 Chamar `AfxOleLockApp` de qualquer objeto que expõe interfaces OLE, se fosse indesejável para o objeto a ser destruído enquanto ainda está sendo usada por um aplicativo cliente. Também chamar `AfxOleUnlockApp` no destruidor de qualquer objeto que chama `AfxOleLockApp` no construtor. Por padrão, `COleDocument` (e as classes derivadas) bloquear e desbloquear o aplicativo automaticamente.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAutomation n º&5;](../../mfc/codesnippet/cpp/application-control_4.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h

##  <a name="a-nameafxoleunlockappa--afxoleunlockapp"></a><a name="afxoleunlockapp"></a>AfxOleUnlockApp  
 Diminui a contagem da estrutura de objetos ativos no aplicativo.  
  
```   
void AFXAPI AfxOleUnlockApp(); 
```  
  
### <a name="remarks"></a>Comentários  
 Consulte `AfxOleLockApp` para obter mais informações.  
  
 Quando o número de objetos ativos chega a zero, **AfxOleOnReleaseAllObjects** é chamado.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [AfxOleLockApp](#afxolelockapp).  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h  

##  <a name="a-nameafxoleregisterserverclassa--afxoleregisterserverclass"></a><a name="afxoleregisterserverclass"></a>AfxOleRegisterServerClass  
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
 `clsid`  
 Referência à ID da classe OLE. do servidor  
  
 `lpszClassName`  
 Ponteiro para uma cadeia de caracteres que contém o nome da classe de objetos do servidor.  
  
 *lpszShortTypeName*  
 Ponteiro para uma cadeia de caracteres que contém o nome curto do tipo de objeto do servidor, como "Gráfico."  
  
 *lpszLongTypeName*  
 Ponteiro para uma cadeia de caracteres que contém o nome longo do tipo de objeto do servidor, como "Gráfico do Microsoft Excel 5.0."  
  
 `nAppType`  
 Um valor obtido a partir de **OLE_APPTYPE** enumeração, especificando o tipo de aplicativo OLE. Os valores possíveis são os seguintes:  
  
- `OAT_INPLACE_SERVER`Servidor tem uma interface de usuário do servidor completo.  
  
- `OAT_SERVER`Servidor dá suporte à incorporação apenas.  
  
- `OAT_CONTAINER`Contêiner oferece suporte a links para objetos incorporados.  
  
- `OAT_DISPATCH_OBJECT``IDispatch`-objeto capaz.  
  
 `rglpszRegister`  
 Matriz de ponteiros para cadeias de caracteres que representa as chaves e valores a serem adicionadas ao registro do sistema OLE se nenhum valor existente para as chaves forem encontrados.  
  
 `rglpszOverwrite`  
 Matriz de ponteiros para cadeias de caracteres que representa as chaves e valores a serem adicionadas ao registro do sistema OLE se o registro contém os valores existentes para as chaves de determinado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a classe de servidor for registrada com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A maioria dos aplicativos pode usar **COleTemplateServer::Register** para registrar os tipos de documento do aplicativo. Se o formato de registro do sistema do seu aplicativo não se ajustam ao padrão típico, você pode usar `AfxOleRegisterServerClass` para obter mais controle.  
  
 O registro consiste em um conjunto de chaves e valores. O `rglpszRegister` e `rglpszOverwrite` argumentos são matrizes de ponteiros para cadeias de caracteres, cada uma consistindo em uma chave e um valor separado por um **nulo** caractere ( `'\0'`). Cada uma dessas cadeias de caracteres pode ter parâmetros substituíveis, cujos locais são marcados por sequências de caracteres a `%1` por meio de `%5`.  
  
 Os símbolos são preenchidos da seguinte maneira:  
  
|Símbolo|Valor|  
|------------|-----------|  
|%1|ID de classe, formatada como uma cadeia de caracteres|  
|%2|Nome da classe|  
|%3|Caminho do arquivo executável|  
|%4|Nome do tipo Short|  
|%5|Nome de tipo longo|  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h

##  <a name="a-nameafxoleseteditmenua--afxoleseteditmenu"></a><a name="afxoleseteditmenu"></a>AfxOleSetEditMenu  
 Implementa a interface do usuário para o *typename* objeto de comando.  
  
```   
void  AFXAPI  AfxOleSetEditMenu(
    COleClientItem* pClient,  
    CMenu* pMenu,  
    UINT iMenuItem,  
    UINT nIDVerbMin,  
    UINT nIDVerbMax = 0,  
    UINT nIDConvert = 0); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pClient`  
 Um ponteiro para o item do cliente OLE.  
  
 `pMenu`  
 Um ponteiro para o objeto de menu a ser atualizado.  
  
 *iMenuItem*  
 O índice do item de menu a ser atualizado.  
  
 `nIDVerbMin`  
 A ID do comando correspondente para o verbo primário.  
  
 *nIDVerbMax*  
 A ID de comando que corresponde ao último verbo.  
  
 *nIDConvert*  
 ID do item de menu converter.  
  
### <a name="remarks"></a>Comentários  
 Se o servidor reconhece apenas um verbo primário, torna-se o item de menu "verbo *typename* objeto" e o `nIDVerbMin` comando é enviado quando o usuário escolhe o comando. Se o servidor reconhece vários verbos, torna-se o item de menu " *typename* objeto" e um submenu que lista todos os verbos aparece quando o usuário escolhe o comando. Quando o usuário escolhe um verbo do submenu, `nIDVerbMin` é enviado se o primeiro verbo for escolhido, `nIDVerbMin` + 1 será enviado se o segundo verbo é escolhida e assim por diante. O padrão `COleDocument` implementação manipula automaticamente a esse recurso.  
  
 Você deve ter a seguinte instrução no script de recurso do aplicativo do cliente (. Arquivo RC):  
  
 **#include \<afxolecl.rc >**  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxole.h 

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

