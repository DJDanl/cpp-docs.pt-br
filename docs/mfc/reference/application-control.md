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
ms.openlocfilehash: 76d8ec079a7c3534211118e60c1d9d95a3a8510a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33355906"
---
# <a name="application-control"></a>Controle do aplicativo
OLE requer controle significativo sobre aplicativos e seus objetos. As DLLs do sistema OLE devem ser capaz de iniciar e libere aplicativos automaticamente, coordenar seus produção e a modificação de objetos e assim por diante. As funções neste tópico atendem a esses requisitos. Além de ser chamados por DLLs do sistema OLE, essas funções, às vezes, devem ser chamadas por aplicativos. 
  
### <a name="application-control"></a>Controle do aplicativo  
  
|||  
|-|-|  
|[AfxOleCanExitApp](#afxolecanexitapp)|Indica se o aplicativo possa ser encerrado.|  
|[AfxOleGetMessageFilter](#afxolegetmessagefilter)|Recupera o filtro de mensagens do aplicativo atual.|  
|[AfxOleGetUserCtrl](#afxolegetuserctrl)|Recupera o sinalizador de controle de usuário atual.|  
|[AfxOleSetUserCtrl](#afxolesetuserctrl)|Define ou limpa o sinalizador de controle de usuário.|  
|[AfxOleLockApp](#afxolelockapp)|Incrementa a contagem global da estrutura do número de objetos ativos em um aplicativo.|  
|[AfxOleLockControl](#afxolelockcontrol)| Bloqueia a fábrica de classe do controle especificado. |
|[AfxOleUnlockApp](#afxoleunlockapp)|Diminui a contagem do framework do número de objetos ativos em um aplicativo.| 
|[AfxOleUnlockControl](#afxoleunlockcontrol)| Desbloqueia a fábrica de classe do controle especificado. |
|[AfxOleRegisterServerClass](#afxoleregisterserverclass)|Registra um servidor no registro do sistema OLE.|  
|[AfxOleSetEditMenu](#afxoleseteditmenu)|Implementa a interface de usuário para o *typename* objeto de comando.|  

  
##  <a name="afxolecanexitapp"></a>  AfxOleCanExitApp  
 Indica se o aplicativo possa ser encerrado.  
  
```   
BOOL AFXAPI AfxOleCanExitApp(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o aplicativo pode sair; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um aplicativo não deve encerrar se houver referências pendentes para seus objetos. As funções globais `AfxOleLockApp` e `AfxOleUnlockApp` incrementar e decrementar, respectivamente, um contador de referências a objetos do aplicativo. O aplicativo não deve ser encerrado quando este contador é diferente de zero. Se o contador for diferente de zero, a janela do aplicativo principal é oculta (não destruído) quando o usuário escolhe o fechamento do menu do sistema ou sair no menu arquivo. O framework chama esta função **CFrameWnd::OnClose**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAutomation#2](../../mfc/codesnippet/cpp/application-control_1.cpp)]  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h 

##  <a name="afxolegetmessagefilter"></a>  AfxOleGetMessageFilter  
 Recupera o filtro de mensagens do aplicativo atual.  
  
```   
COleMessageFilter* AFXAPI AfxOleGetMessageFilter(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o filtro de mensagem atual.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função para acessar o atual `COleMessageFilter`-derivado de objeto, assim como você poderia chamar `AfxGetApp` para acessar o objeto de aplicativo atual.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAutomation#3](../../mfc/codesnippet/cpp/application-control_2.cpp)]  
  
 [!code-cpp[NVC_MFCAutomation#4](../../mfc/codesnippet/cpp/application-control_3.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxwin.h 

##  <a name="afxolegetuserctrl"></a>  AfxOleGetUserCtrl  
 Recupera o sinalizador de controle de usuário atual.  
  
```   
BOOL AFXAPI AfxOleGetUserCtrl(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário estiver no controle do aplicativo; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O usuário está no controle do aplicativo quando o usuário explicitamente é aberto ou criado um novo documento. O usuário também está no controle se o aplicativo não foi iniciado pelo sistema OLE DLLs — em outras palavras, se o usuário iniciou o aplicativo com o shell do sistema.  

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
 O framework chama esta função quando o usuário cria ou carrega um documento, mas não quando um documento for carregado ou criado por meio de uma ação indireta, como o carregamento de um objeto inserido em um aplicativo de contêiner.  
  
 Chame essa função se outras ações em seu aplicativo devem colocar o usuário no controle do aplicativo.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h

##  <a name="afxolelockapp"></a>  AfxOleLockApp  
 Incrementa a contagem global da estrutura do número de objetos ativos no aplicativo.  
  
```   
void AFXAPI AfxOleLockApp(); 
```  
  
### <a name="remarks"></a>Comentários  
 A estrutura mantém uma contagem do número de objetos ativos em um aplicativo. O `AfxOleLockApp` e `AfxOleUnlockApp` funções, respectivamente, incrementar e decrementar Essa contagem.  
  
 Quando o usuário tenta fechar um aplicativo que tenha objetos ativos — um aplicativo para o qual a contagem de objetos ativos é diferente de zero, o framework oculta a exibição do usuário em vez de desligá-lo completamente do aplicativo. O `AfxOleCanExitApp` função indica se o aplicativo possa ser encerrado.  
  
 Chamar `AfxOleLockApp` de qualquer objeto que expõe interfaces OLE, se for desejável para o objeto a ser destruído enquanto ainda está sendo usado por um aplicativo cliente. Também chamar `AfxOleUnlockApp` no destruidor de qualquer objeto que chama `AfxOleLockApp` no construtor. Por padrão, `COleDocument` (e classes derivadas) automaticamente bloquear e desbloquear o aplicativo.  
  
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
  
 Quando chega a zero, o número de objetos ativos **AfxOleOnReleaseAllObjects** é chamado.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [AfxOleLockApp](#afxolelockapp).  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h  

 ## <a name="afxolelockcontrol"></a>AfxOleLockControl
Bloqueia a fábrica de classe do controle especificado para que os dados criados dinamicamente associados com o controle permanecem na memória.  
   
### <a name="syntax"></a>Sintaxe    
```
BOOL AFXAPI AfxOleLockControl(  REFCLSID clsid  );  
BOOL AFXAPI AfxOleLockControl( LPCTSTR lpszProgID );  
```
### <a name="parameters"></a>Parâmetros  
 `clsid`  
 A ID exclusiva de classe do controle.  
  
 `lpszProgID`  
 A ID exclusiva do controle.  
   
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fábrica de classe do controle foi bloqueada com êxito; Caso contrário, 0.  
   
### <a name="remarks"></a>Comentários  
 Isso pode acelerar significativamente a exibição dos controles. Por exemplo, uma vez você criar um controle em uma caixa de diálogo e bloqueia o controle com `AfxOleLockControl`, você não precisa criar e eliminá-lo novamente sempre que a caixa de diálogo é mostrada ou destruída. Se o usuário abre e fecha uma caixa de diálogo várias vezes, os controles de bloqueio pode melhorar significativamente o desempenho. Quando você estiver pronto para destruir o controle, chame `AfxOleUnlockControl`.  
   
### <a name="example"></a>Exemplo  
```cpp
// Starts and locks control's (Microsoft Calendar) class factory. 
// Control will remain in memory for lifetime of
// application or until AfxOleUnlockControl() is called.

AfxOleLockControl(_T("MSCAL.Calendar"));
```
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** < afxwin.h >  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [AfxOleUnlockControl](#afxoleunlockcontrol)
 
##  <a name="afxoleregisterserverclass"></a>  AfxOleRegisterServerClass  
 Esta função permite que você registre seu servidor no registro do sistema OLE.  
  
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
 Referência à ID de classe OLE. do servidor  
  
 `lpszClassName`  
 Ponteiro para uma cadeia de caracteres que contém o nome da classe de objetos do servidor.  
  
 *lpszShortTypeName*  
 Ponteiro para uma cadeia de caracteres que contém o nome curto do tipo de objeto do servidor, como "Gráfico."  
  
 *lpszLongTypeName*  
 Ponteiro para uma cadeia de caracteres que contém o nome longo do tipo de objeto do servidor, como "Gráfico do Microsoft Excel 5.0".  
  
 `nAppType`  
 Um valor obtido o **OLE_APPTYPE** enumeração, especificando o tipo de aplicativo OLE. Os valores possíveis são os seguintes:  
  
- `OAT_INPLACE_SERVER` Servidor tem uma interface de usuário do servidor completo.  
  
- `OAT_SERVER` Servidor dá suporte apenas a inserção.  
  
- `OAT_CONTAINER` Contêiner oferece suporte a links para objetos incorporados.  
  
- `OAT_DISPATCH_OBJECT` `IDispatch`-objeto capaz.  
  
 `rglpszRegister`  
 Matriz de ponteiros para cadeias de caracteres que representa as chaves e valores a serem adicionadas ao registro do sistema OLE se nenhum valor existente para as chaves forem encontrados.  
  
 `rglpszOverwrite`  
 Matriz de ponteiros para cadeias de caracteres que representa as chaves e valores a serem adicionadas ao registro do sistema OLE se o registro contém os valores existentes para as chaves especificadas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a classe de servidor for registrada com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A maioria dos aplicativos podem usar **COleTemplateServer::Register** para registrar os tipos de documento do aplicativo. Se o formato de registro do sistema do seu aplicativo não se ajustam ao padrão típico, você pode usar `AfxOleRegisterServerClass` para obter mais controle.  
  
 O registro consiste em um conjunto de chaves e valores. O `rglpszRegister` e `rglpszOverwrite` argumentos são matrizes de ponteiros para cadeias de caracteres, cada consiste em uma chave e um valor separado por um **nulo** caractere ( `'\0'`). Cada uma dessas cadeias de caracteres pode ter parâmetros substituíveis cujos locais são marcados pelas sequências de caracteres `%1` por meio de `%5`.  
  
 Os símbolos são preenchidos da seguinte maneira:  
  
|Símbolo|Valor|  
|------------|-----------|  
|%1|ID de classe, formatada como uma cadeia de caracteres|  
|%2|Nome da classe|  
|%3|Caminho do arquivo executável|  
|%4|Nome do tipo curto|  
|%5|Nome de tipo longo|  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h

##  <a name="afxoleseteditmenu"></a>  AfxOleSetEditMenu  
 Implementa a interface de usuário para o *typename* objeto de comando.  
  
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
 `pClient`  
 Um ponteiro para o item OLE de cliente.  
  
 `pMenu`  
 Um ponteiro para o objeto de menu a ser atualizado.  
  
 *iMenuItem*  
 O índice do item de menu a ser atualizado.  
  
 `nIDVerbMin`  
 A ID do comando correspondente para o verbo primário.  
  
 *nIDVerbMax*  
 A ID de comando que corresponde ao último verbo.  
  
 *nIDConvert*  
 ID do item de menu Convert.  
  
### <a name="remarks"></a>Comentários  
 Se o servidor reconhece apenas um verbo primário, torna-se o item de menu "verbo *typename* objeto" e o `nIDVerbMin` comando é enviado quando o usuário escolhe o comando. Se o servidor as reconheça vários verbos, torna-se o item de menu " *typename* objeto" e um submenu que lista todos os verbos aparece quando o usuário escolhe o comando. Quando o usuário escolhe um verbo no submenu, `nIDVerbMin` é enviado se o primeiro verbo for escolhido, `nIDVerbMin` + 1 será enviado se o segundo verbo é escolhida e assim por diante. O padrão `COleDocument` implementação manipula automaticamente esse recurso.  
  
 Você deve ter a seguinte instrução no script de recurso do aplicativo do cliente (. Arquivo RC):  
  
 **#include \<afxolecl.rc >**  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxole.h 

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

## <a name="afxoleunlockcontrol"></a> AfxOleUnlockControl
Desbloqueia a fábrica de classe do controle especificado.  
   
### <a name="syntax"></a>Sintaxe  
  ```
BOOL AFXAPI AfxOleUnlockControl( REFCLSID clsid );  
BOOL AFXAPI AfxOleUnlockControl( LPCTSTR lpszProgID );  
```
### <a name="parameters"></a>Parâmetros  
 `clsid`  
 A ID exclusiva de classe do controle.  
  
 `lpszProgID`  
 A ID exclusiva do controle.  
   
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fábrica de classe do controle foi desbloqueada com sucesso; Caso contrário, 0.  
   
### <a name="remarks"></a>Comentários  
 Um controle é bloqueado de `AfxOleLockControl`, de modo que os dados criados dinamicamente associados com o controle permanecem na memória. Isso pode acelerar significativamente a exibição do controle porque o controle não precisa ser criado e destruído toda vez que ele é exibido. Quando você estiver pronto para destruir o controle, chame `AfxOleUnlockControl`.  
   
### <a name="example"></a>Exemplo  
 ```cpp
// Unlock control's (Microsoft Calendar Control) class factory.

AfxOleUnlockControl(_T("MSCAL.Calendar"));

```
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** < afxwin.h >  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)  
 [AfxOleLockControl](#afxolelockcontrol)

