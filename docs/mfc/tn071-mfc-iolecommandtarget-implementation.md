---
title: 'TN071: Implementação de IOleCommandTarget MFC | Microsoft Docs'
ms.custom: ''
ms.date: 06/28/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- IOleCommandTarget
dev_langs:
- C++
helpviewer_keywords:
- TN071 [MFC]
- IOleCommandTarget interface [MFC]
ms.assetid: 3eef571e-6357-444d-adbb-6f734a0c3161
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ebd796690407fe0e65bc790c52477c7e4d149250
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37122615"
---
# <a name="tn071-mfc-iolecommandtarget-implementation"></a>TN071: implementação de IOleCommandTarget MFC

> [!NOTE]
> A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.

O `IOleCommandTarget` interface permite que objetos e seus contêineres para enviar comandos ao outro. Por exemplo, barras de ferramentas de um objeto podem conter botões para comandos como `Print`, `Print Preview`, `Save`, `New`, e `Zoom`. Se tal objeto foram inseridos em um contêiner que dá suporte a `IOleCommandTarget`, o objeto pode habilitar seus botões e encaminhar os comandos para o contêiner de processamento quando o usuário clicou-los. Se quiser que um contêiner do objeto incorporado para imprimir em si, ele pode fazer essa solicitação enviando um comando por meio de `IOleCommandTarget` interface do objeto inserido.

`IOleCommandTarget` é uma interface de automação em que ele é usado por um cliente para chamar métodos em um servidor. No entanto, usar `IOleCommandTarget` salva a sobrecarga de chamadas por meio de interfaces de automação porque os programadores não precisam usar geralmente caros `Invoke` método `IDispatch`.

Em MFC, o `IOleCommandTarget` interface é usada pelos servidores do documento ativo para permitir que os contêineres de documento ativo enviar comandos ao servidor. A classe de servidor do documento ativo, `CDocObjectServerItem`, usa mapas de interface MFC (consulte [TN038: implementação de IUnknown MFC/OLE](../mfc/tn038-mfc-ole-iunknown-implementation.md)) para implementar o `IOleCommandTarget` interface.

`IOleCommandTarget` também é implementado no `COleFrameHook` classe. `COleFrameHook` é uma classe do MFC não documentada que implementa a funcionalidade de janela do quadro de contêineres de edição no local. `COleFrameHook` também usa mapas de interface do MFC para implementar o `IOleCommandTarget` interface. `COleFrameHook`da implementação de `IOleCommandTarget` encaminha comandos OLE para `COleDocObjectItem`-derivado contêineres de documento ativo. Isso permite que qualquer contêiner de documento ativo do MFC receber mensagens de servidores independentes documento ativo.

## <a name="mfc-ole-command-maps"></a>Mapas de comando OLE do MFC

Os desenvolvedores MFC podem tirar proveito de `IOleCommandTarget` usando OLE do MFC mapas de comando. Mapas de comando do OLE são como mapas de mensagem porque eles podem ser usados para mapear comandos OLE para funções de membro da classe que contém o mapa de comando. Para executar esse trabalho, colocar as macros na estrutura do comando para especificar o grupo de comando OLE da ID de comando, o comando OLE e o comando que você deseja manipular o [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem que será enviada quando o comando OLE é recebido. MFC também oferece inúmeras macros predefinidas para comandos OLE padrão. Para obter uma lista de OLE padrão comandos que foram originalmente projetados para usar com aplicativos do Microsoft Office, consulte a enumeração OLECMDID, que é definida em docobj.h.

Quando um comando OLE é recebido por um aplicativo MFC que contém um mapa de comando OLE, MFC tenta localizar o ID de comando e o grupo de comando para o comando solicitado no mapa de comando OLE do aplicativo. Se uma correspondência for encontrada, uma mensagem WM_COMMAND é enviada para o aplicativo que contém o mapa de comando com a ID do comando solicitado. (Consulte a descrição de `ON_OLECMD` abaixo.) Dessa forma, os comandos OLE distribuídos em um aplicativo são transformados em mensagens WM_COMMAND pelo MFC. As mensagens WM_COMMAND, em seguida, são roteadas através de mapas de mensagem do aplicativo usando o padrão MFC [roteamento de comando](../mfc/command-routing.md) arquitetura.

Ao contrário de mapas de mensagem, não há suporte para mapas de comando OLE do MFC pelo ClassWizard. Os desenvolvedores MFC devem adicionar suporte ao mapa de comando OLE e entradas do mapa de comando OLE manualmente. Comando OLE mapas podem ser adicionados para servidores de documentos ativos do MFC em qualquer classe que é a cadeia de roteamento de mensagens WM_COMMAND no momento em que o documento ativo está ativo no local em um contêiner. Essas classes incluem classes do aplicativo derivadas de [CWinApp](../mfc/reference/cwinapp-class.md), [CView](../mfc/reference/cview-class.md), [CDocument](../mfc/reference/cdocument-class.md), e [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md). Contêineres de documentos ativos, mapas de comando OLE só podem ser adicionados para o [COleDocObjectItem](../mfc/reference/coledocobjectitem-class.md)-classe derivada. Além disso, em contêineres de documento ativo, as mensagens WM_COMMAND serão apenas enviadas para o mapa de mensagem no `COleDocObjectItem`-classe derivada.

## <a name="ole-command-map-macros"></a>Macros de mapa de comando OLE

Use as seguintes macros para adicionar funcionalidade de mapa de comando para sua classe:

```cpp
DECLARE_OLECMD_MAP ()
```

Esta macro vai para a declaração de classe (normalmente no arquivo de cabeçalho) da classe que contém o mapa de comando.

```cpp
BEGIN_OLECMD_MAP(theClass, baseClass)
```

*theClass*  
 Nome da classe que contém o mapa de comando.

*baseClass*  
 Nome da classe base da classe que contém o mapa de comando.

Esta macro marca o início do mapa de comando. Use esta macro no arquivo de implementação para a classe que contém o mapa de comando.

```
END_OLECMD_MAP()
```

Esta macro marca o fim do mapa de comando. Use esta macro no arquivo de implementação para a classe que contém o mapa de comando. Esta macro sempre deve seguir a macro BEGIN_OLECMD_MAP.

```
ON_OLECMD(pguid, olecmdid, id)
```

*pguid*  
 Ponteiro para o GUID do grupo de comandos do comando OLE. Esse parâmetro é **nulo** para o grupo de comando OLE padrão.

*olecmdid*  
 ID de comando OLE do comando a ser invocado.

*id*  
 ID da mensagem WM_COMMAND a ser enviado para o aplicativo que contém o mapa de comando quando o comando OLE é invocado.

Use a macro ON_OLECMD no mapa de comando para adicionar entradas para os comandos OLE que você deseja manipular. Quando os comandos OLE são recebidos, eles serão convertidos para a mensagem WM_COMMAND especificada e roteados por meio de mapa de mensagem do aplicativo usando a arquitetura de roteamento de comando do MFC padrão.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como adicionar o recurso de manipulação de comandos OLE para um servidor de documento ativo de MFC para lidar com o [OLECMDID_PRINT](http://msdn.microsoft.com/library/windows/desktop/ms691264) comando OLE. Este exemplo presume que você usou AppWizard para gerar um aplicativo MFC que é um servidor de documento ativo.

1. No seu `CView`-derivado de cabeçalho da classe do arquivo, adicione a macro DECLARE_OLECMD_MAP à declaração de classe.

    > [!NOTE]
    > Use o `CView`-classe derivada, porque é uma das classes do servidor do documento ativo que está na cadeia de roteamento de mensagens WM_COMMAND.

    ```cpp
    class CMyServerView : public CView
    {
    protected: // create from serialization only
        CMyServerView();
        DECLARE_DYNCREATE(CMyServerView)
        DECLARE_OLECMD_MAP()
        // . . .
    };
    ```

2. No arquivo de implementação para o `CView`-derivado da classe, adicione as macros BEGIN_OLECMD_MAP e END_OLECMD_MAP:

    ```cpp
    BEGIN_OLECMD_MAP(CMyServerView, CView)

    END_OLECMD_MAP()
    ```

3. Para processar o comando de impressão padrão OLE, adicione um [ON_OLECMD](reference/message-map-macros-mfc.md#on_olecmd) macro para o mapa de comando especificando a ID de comando OLE para o comando de impressão padrão e **ID_FILE_PRINT** para a ID de WM_COMMAND. **ID_FILE_PRINT** é o padrão de ID de comando de impressão usado por aplicativos MFC AppWizard gerado:

    ```
    BEGIN_OLECMD_MAP(CMyServerView, CView)
        ON_OLECMD(NULL, OLECMDID_PRINT, ID_FILE_PRINT)
    END_OLECMD_MAP()
    ```

Observe que uma das macros de comando OLE padrão, definidas em afxdocob.h, pode ser usada no lugar de macro ON_OLECMD porque **OLECMDID_PRINT** é uma ID de comando OLE padrão. A macro ON_OLECMD_PRINT realizará a mesma tarefa a macro ON_OLECMD mostrada acima.

Quando um aplicativo de contêiner envia esse servidor um **OLECMDID_PRINT** comando por meio do servidor `IOleCommandTarget` interface, o MFC imprimindo o manipulador de comandos será invocado no servidor, fazendo com que o servidor de impressão do aplicativo. Código do contêiner do documento ativo para invocar o comando print adicionado nas etapas acima deve ter esta aparência:

```cpp
void CContainerCntrItem::DoOleCmd()
{
    IOleCommandTarget *pCmd = NULL;
    HRESULT hr = E_FAIL;
    OLECMD ocm={OLECMDID_PRINT, 0};

    hr = m_lpObject->QueryInterface(
        IID_IOleCommandTarget,reinterpret_cast<void**>(&pCmd));

    if (FAILED(hr))
        return;

    hr = pCmd->QueryStatus(NULL, 1, &ocm, NULL);

    if (SUCCEEDED(hr) && (ocm.cmdf& OLECMDF_ENABLED))
    {
        //Command is available and enabled so call it
        COleVariant vIn;
        COleVariant vOut;
        hr = pCmd->Exec(NULL, OLECMDID_PRINT,
            OLECMDEXECOPT_DODEFAULT, &vIn, &vOut);
        ASSERT(SUCCEEDED(hr));
    }
    pCmd->Release();
}
```

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)  
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)  
