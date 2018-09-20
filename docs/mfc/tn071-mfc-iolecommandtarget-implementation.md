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
ms.openlocfilehash: 6d8d4b0f740e69b57944cb35f2213ae0fd54b511
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46386282"
---
# <a name="tn071-mfc-iolecommandtarget-implementation"></a>TN071: implementação de IOleCommandTarget MFC

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

O `IOleCommandTarget` interface permite que objetos e seus contêineres para enviar comandos uns aos outros. Por exemplo, barras de ferramentas de um objeto podem conter botões para comandos como `Print`, `Print Preview`, `Save`, `New`, e `Zoom`. Se esse objeto foram inseridos em um contêiner que dá suporte a `IOleCommandTarget`, o objeto pode habilitar seus botões e encaminhar os comandos para o contêiner para o processamento quando o usuário clicou-los. Se quisesse que um contêiner do objeto incorporado para imprimir em si, ele pode fazer essa solicitação enviando um comando por meio de `IOleCommandTarget` interface do objeto inserido.

`IOleCommandTarget` é uma interface de automação em que ele é usado por um cliente para invocar métodos em um servidor. No entanto, usando `IOleCommandTarget` evita a sobrecarga de fazer chamadas por meio de interfaces de automação, porque os programadores não precisam usar o costuma ser caro `Invoke` método `IDispatch`.

No MFC, o `IOleCommandTarget` interface é usada pelos servidores do documento ativo para permitir que os contêineres de documento ativo enviar comandos ao servidor. A classe de servidor de documento ativo `CDocObjectServerItem`, usa mapas de interface MFC (consulte [TN038: implementação de IUnknown MFC/OLE](../mfc/tn038-mfc-ole-iunknown-implementation.md)) para implementar o `IOleCommandTarget` interface.

`IOleCommandTarget` também é implementado de `COleFrameHook` classe. `COleFrameHook` é uma classe do MFC não documentada que implementa a funcionalidade de janela de quadro de contêineres de edição in-loco. `COleFrameHook` também usa mapas de interface do MFC para implementar o `IOleCommandTarget` interface. `COleFrameHook`da implementação de `IOleCommandTarget` encaminha comandos OLE para `COleDocObjectItem`-derivado contêineres de documento ativo. Isso permite que qualquer contêiner de documento ativo do MFC receber mensagens de servidores independentes de documento ativo.

## <a name="mfc-ole-command-maps"></a>Mapas de comando OLE do MFC

Os desenvolvedores MFC podem tirar proveito de `IOleCommandTarget` mapas de comando, usando o OLE do MFC. Mapas de comando OLE são como mapas de mensagem, pois eles podem ser usados para mapear comandos OLE para funções de membro da classe que contém o mapa de comando. Para fazer isso funcionar, colocar as macros no mapa de comando para especificar o grupo de comandos OLE do comando que você deseja manipular, o comando OLE e a ID de comando do [WM_COMMAND](/windows/desktop/menurc/wm-command) mensagem que será enviada quando o comando OLE é recebido. MFC também fornece um número de macros predefinidas para comandos OLE padrão. Para obter uma lista da OLE padrão comandos que foram originalmente criados para usar com aplicativos do Microsoft Office, consulte a enumeração OLECMDID, que é definida no docobj.h.

Quando um comando OLE é recebido por um aplicativo do MFC que contém um mapa de comando OLE, o MFC tenta encontrar a ID de comando e o grupo de comando para o comando solicitado no mapa de comando OLE do aplicativo. Se uma correspondência for encontrada, uma mensagem WM_COMMAND é enviada para o aplicativo que contém o mapa de comando com a ID do comando solicitado. (Consulte a descrição da `ON_OLECMD` abaixo.) Dessa forma, os comandos OLE expedidos para um aplicativo são transformados em mensagens WM_COMMAND pelo MFC. As mensagens WM_COMMAND, em seguida, são roteadas por meio de mapas de mensagem do aplicativo usando o padrão do MFC [roteamento de comando](../mfc/command-routing.md) arquitetura.

Ao contrário de mapas de mensagem, não há suporte para mapas de comando OLE do MFC pelo ClassWizard. Os desenvolvedores MFC devem adicionar suporte ao mapa de comando OLE e entradas de mapa de comando OLE manualmente. Comando OLE mapas podem ser adicionados ao Active Directory MFC servidores de documentos em qualquer classe que está na cadeia de roteamento de mensagens WM_COMMAND no momento em que o documento ativo está ativo no local em um contêiner. Essas classes incluem as classes do aplicativo derivadas [CWinApp](../mfc/reference/cwinapp-class.md), [CView](../mfc/reference/cview-class.md), [CDocument](../mfc/reference/cdocument-class.md), e [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md). Contêineres de documento ativo, mapas de comando OLE só podem ser adicionados para o [COleDocObjectItem](../mfc/reference/coledocobjectitem-class.md)-classe derivada. Além disso, em contêineres de documento ativo, as mensagens WM_COMMAND serão apenas expedidas para o mapa de mensagem no `COleDocObjectItem`-classe derivada.

## <a name="ole-command-map-macros"></a>Macros de mapa de comando OLE

Use as macros a seguir para adicionar funcionalidade de mapa do comando à sua classe:

```cpp
DECLARE_OLECMD_MAP ()
```

Essa macro vai para a declaração de classe (normalmente no arquivo de cabeçalho) da classe que contém o mapa de comando.

```cpp
BEGIN_OLECMD_MAP(theClass, baseClass)
```

*theClass*<br/>
Nome da classe que contém o mapa de comando.

*baseClass*<br/>
Nome da classe base da classe que contém o mapa de comando.

Essa macro marca o início do mapa do comando. Use esta macro no arquivo de implementação para a classe que contém o mapa de comando.

```
END_OLECMD_MAP()
```

Essa macro marca o fim do mapa do comando. Use esta macro no arquivo de implementação para a classe que contém o mapa de comando. Essa macro deve sempre seguir a macro BEGIN_OLECMD_MAP.

```
ON_OLECMD(pguid, olecmdid, id)
```

*pguid*<br/>
Ponteiro para o GUID do grupo de comando do comando OLE. Esse parâmetro é **nulo** para o grupo de comandos OLE padrão.

*olecmdid*<br/>
ID de comando OLE do comando a ser invocado.

*id*<br/>
ID da mensagem WM_COMMAND seja enviado para o aplicativo que contém o mapa de comando quando esse comando OLE é invocado.

Use a macro ON_OLECMD no mapa de comando para adicionar entradas para os comandos OLE que você deseja manipular. Quando os comandos OLE são recebidos, elas serão convertidas para a mensagem WM_COMMAND especificada e roteadas por meio do mapa de mensagens do aplicativo usando a arquitetura de roteamento de comando do MFC padrão.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como adicionar funcionalidade de manipulação de comandos OLE para um servidor de documento ativo do MFC para lidar com o [OLECMDID_PRINT](/windows/desktop/api/docobj/ne-docobj-olecmdid) comando OLE. Este exemplo presume que você usou o AppWizard para gerar um aplicativo do MFC que é um servidor de documento ativo.

1. No seu `CView`-derivado do cabeçalho da classe de arquivo, adicione a macro DECLARE_OLECMD_MAP à declaração de classe.

    > [!NOTE]
    > Use o `CView`-classe derivada, porque ele é uma das classes do servidor de documento ativo que está na cadeia de roteamento de mensagens WM_COMMAND.

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

3. Para lidar com o comando de impressão padrão do OLE, adicione uma [ON_OLECMD](reference/message-map-macros-mfc.md#on_olecmd) macro ao mapa de comando, especificando a ID de comando OLE para o comando de impressão padrão e **ID_FILE_PRINT** para a ID de WM_COMMAND. **ID_FILE_PRINT** é o padrão de ID de comando print usada por aplicativos gerados pelo AppWizard MFC:

    ```
    BEGIN_OLECMD_MAP(CMyServerView, CView)
        ON_OLECMD(NULL, OLECMDID_PRINT, ID_FILE_PRINT)
    END_OLECMD_MAP()
    ```

Observe que uma das macros de comando OLE padrão, definidas no afxdocob.h, pode ser usada no lugar de macro ON_OLECMD porque **OLECMDID_PRINT** é uma ID de comando OLE padrão. A macro ON_OLECMD_PRINT realizará a mesma tarefa que a macro ON_OLECMD mostrada acima.

Quando um aplicativo de contêiner envia esse servidor um **OLECMDID_PRINT** comando por meio do servidor `IOleCommandTarget` interface, o MFC no manipulador de comandos de impressão será invocada no servidor, fazendo com que o servidor de impressão do aplicativo. Código do contêiner do documento ativo para invocar o comando print adicionado nas etapas acima seria algo parecido com isto:

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

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
