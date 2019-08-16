---
title: 'TN001: Registro de classe de janela'
ms.date: 11/04/2016
f1_keywords:
- vc.registration
helpviewer_keywords:
- TN001
- WNDCLASS [MFC]
- AfxRegisterClass function
ms.assetid: 1abf678e-f220-4606-85e0-03df32f64c54
ms.openlocfilehash: 95e35ddd6f55c955bc2adb7b4db2460ae84a6dc7
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69513554"
---
# <a name="tn001-window-class-registration"></a>TN001: Registro de classe de janela

Esta observação descreve as rotinas do MFC que registram os [WNDCLASS](/windows/win32/api/winuser/ns-winuser-wndclassw)especiais necessários ao Microsoft Windows. São `WNDCLASS` discutidos atributos específicos usados pelo MFC e pelo Windows.

## <a name="the-problem"></a>O problema

Os atributos de um objeto [CWnd](../mfc/reference/cwnd-class.md) , como um `HWND` identificador no Windows, são armazenados em dois locais: o objeto Window e o `WNDCLASS`. `WNDCLASS` O nome do é passado para funções gerais de criação de janela, como [CWnd:: Create](../mfc/reference/cwnd-class.md#create) e [CFrameWnd:: Create](../mfc/reference/cframewnd-class.md#create) no parâmetro *lpszClassName* .

Isso `WNDCLASS` deve ser registrado por meio de um dos quatro meios:

- Implicitamente, usando um MFC fornecido `WNDCLASS`.

- Implicitamente, por meio da subclasse de um controle do Windows (ou algum outro controle).

- Explicitamente chamando o MFC [AfxRegisterWndClass](../mfc/reference/application-information-and-management.md#afxregisterwndclass) ou [AfxRegisterClass](../mfc/reference/application-information-and-management.md#afxregisterclass).

- Explicitamente chamando a rotina do Windows [registerClass](/windows/win32/api/winuser/nf-winuser-registerclassw).

## <a name="wndclass-fields"></a>Campos WNDCLASS

A `WNDCLASS` estrutura consiste em vários campos que descrevem uma classe de janela. A tabela a seguir mostra os campos e especifica como eles são usados em um aplicativo MFC:

|Campo|Descrição|
|-----------|-----------------|
|*lpfnWndProc*|proc de janela, deve ser um`AfxWndProc`|
|*cbClsExtra*|Não usado (deve ser zero)|
|*cbWndExtra*|Não usado (deve ser zero)|
|*hInstance*|preenchido automaticamente com [AfxGetInstanceHandle](../mfc/reference/application-information-and-management.md#afxgetinstancehandle)|
|*hIcon*|ícone para janelas de quadros, consulte abaixo|
|*hCursor*|cursor para quando o mouse estiver sobre a janela, consulte abaixo|
|*hbrBackground*|cor do plano de fundo, veja abaixo|
|*lpszMenuName*|Não usado (deve ser nulo)|
|*lpszClassName*|nome da classe, consulte abaixo|

## <a name="provided-wndclasses"></a>WNDCLASSes fornecido

Versões anteriores do MFC (antes do MFC 4,0) forneciam várias classes de janela predefinidas. Essas classes de janela não são mais fornecidas por padrão. Os aplicativos devem `AfxRegisterWndClass` ser usados com os parâmetros apropriados.

Se o aplicativo fornecer um recurso com a ID de recurso especificada (por exemplo, AFX_IDI_STD_FRAME), o MFC usará esse recurso. Caso contrário, ele usará o recurso padrão. Para o ícone, o ícone de aplicativo padrão é usado e, para o cursor, o cursor de seta padrão é usado.

Dois ícones dão suporte a aplicativos MDI com tipos de documento únicos: um ícone para o aplicativo principal, o outro ícone para o icônico documento/MDIChild do Windows. Para vários tipos de documentos com ícones diferentes, você deve registrar `WNDCLASS`es adicionais ou usar a função [CFrameWnd:: LoadFrame](../mfc/reference/cframewnd-class.md#loadframe) .

`CFrameWnd::LoadFrame`o registrará `WNDCLASS` um usando a ID do ícone que você especificar como o primeiro parâmetro e os seguintes atributos padrão:

- estilo de classe: CS_DBLCLKS &#124; CS_HREDRAW &#124; CS_VREDRAW;

- ícone AFX_IDI_STD_FRAME

- cursor de seta

- Cor do plano de fundo do COLOR_WINDOW

Os valores da cor do plano de fundo e do cursor para o [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) não são usados, pois `CMDIFrameWnd` a área do cliente do é totalmente coberta pela janela **MdiClient** . A Microsoft não incentiva a subclasse da janela **MdiClient** , portanto, use as cores padrão e os tipos de cursor quando possível.

## <a name="subclassing-and-superclassing-controls"></a>Subclasses e controles de sobreclasse

Se você subturma ou superclasse de um controle do Windows (por exemplo, [CButton](../mfc/reference/cbutton-class.md)), sua classe `WNDCLASS` obtém automaticamente os atributos fornecidos na implementação do Windows desse controle.

## <a name="the-afxregisterwndclass-function"></a>A função AfxRegisterWndClass

O MFC fornece uma função auxiliar para registrar uma classe de janela. Dado um conjunto de atributos (estilo de classe de janela, cursor, pincel de plano de fundo e ícone), um nome sintético é gerado e a classe de janela resultante é registrada. Por exemplo,

```
const char* AfxRegisterWndClass(UINT nClassStyle,
    HCURSOR hCursor,
    HBRUSH hbrBackground,
    HICON hIcon);
```

Essa função retorna uma cadeia de caracteres temporária do nome da classe de janela registrada gerada. Para obter mais informações sobre essa função, consulte [AfxRegisterWndClass](../mfc/reference/application-information-and-management.md#afxregisterwndclass).

A cadeia de caracteres retornada é um ponteiro temporário para um buffer de cadeia de caracteres estática. Ele é válido até a próxima chamada para `AfxRegisterWndClass`. Se você quiser manter essa cadeia de caracteres, armazene-a em uma variável [CString](../atl-mfc-shared/using-cstring.md) , como neste exemplo:

```
CString strWndClass = AfxRegisterWndClass(CS_DBLCLK, ...);

...
CWnd* pWnd = new CWnd;
pWnd->Create(strWndClass, ...);

...
```

`AfxRegisterWndClass`lançará um [CResourceException](../mfc/reference/cresourceexception-class.md) se a classe Window não for registrada (devido a parâmetros inválidos ou memória insuficiente do Windows).

## <a name="the-registerclass-and-afxregisterclass-functions"></a>As funções RegisterClass e AfxRegisterClass

Se desejar fazer algo mais sofisticado do que o `AfxRegisterWndClass` fornecido, você poderá chamar a API `RegisterClass` do Windows ou a função `AfxRegisterClass`MFC. As `CWnd`funções, [CFrameWnd](../mfc/reference/cframewnd-class.md) e [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) `Create` usam um nome de cadeia de caracteres *lpszClassName* para a classe Window como o primeiro parâmetro. Você pode usar qualquer nome de classe de janela registrada, independentemente do método usado para registrá-lo.

É importante usar `AfxRegisterClass` (ou `AfxRegisterWndClass`) em uma dll no Win32. O Win32 não cancela automaticamente o registro de classes registradas por uma DLL, portanto, você deve cancelar explicitamente o registro de classes quando a DLL for encerrada. O uso `AfxRegisterClass` do `RegisterClass` em vez disso é manipulado automaticamente para você. `AfxRegisterClass`mantém uma lista de classes exclusivas registradas por sua DLL e cancelará seu registro automaticamente quando a DLL for encerrada. Ao usar `RegisterClass` o em uma dll, você deve garantir que todas as classes tenham o registro cancelado quando a DLL for encerrada (em sua função [DllMain](/windows/win32/Dlls/dllmain) ). A falha em fazer isso pode `RegisterClass` causar uma falha inesperada quando outro aplicativo cliente tenta usar sua dll.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
