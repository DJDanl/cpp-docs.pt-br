---
title: DLLs regulares do MFC vinculadas dinamicamente ao MFC
ms.date: 11/04/2016
helpviewer_keywords:
- regular MFC DLLs [C++], dynamically linked to MFC
- AFX_MANAGE_STATE macro
- DLLs [C++], regular
- shared DLL versions [C++]
- dynamically linked DLLs [C++]
ms.assetid: b4f7ab92-8723-42a5-890e-214f4e29dcd0
ms.openlocfilehash: 3bfed5f75dab4c501708950fdb99f53c40ec142c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62314995"
---
# <a name="regular-mfc-dlls-dynamically-linked-to-mfc"></a>DLLs regulares do MFC vinculadas dinamicamente ao MFC

Uma DLL do MFC regular vinculada dinamicamente ao MFC é uma DLL que usa o MFC internamente, e as funções exportadas na DLL podem ser chamadas por executáveis MFC ou não MFC. Como o nome descreve, esse tipo de DLL é criado usando a versão da biblioteca de vínculo dinâmico do MFC (também conhecida como a versão compartilhada do MFC). Normalmente, as funções são exportadas de uma DLL do MFC regular usando a interface C padrão.

Você deve adicionar a `AFX_MANAGE_STATE` macro no início de todas as funções exportadas em DLLs do MFC regulares que se vinculam DINAMICAMENTE ao MFC para definir o estado atual do módulo como o da dll. Isso é feito adicionando a seguinte linha de código ao início das funções exportadas da DLL:

```
AFX_MANAGE_STATE(AfxGetStaticModuleState( ))
```

Uma DLL do MFC regular, vinculada dinamicamente ao MFC, tem os seguintes recursos:

- Esse é um novo tipo de DLL introduzido pelo Visual C++ 4,0.

- O executável do cliente pode ser escrito em qualquer linguagem que dê suporte ao uso de DLLs (C, C++, Pascal, Visual Basic e assim por diante); Não precisa ser um aplicativo MFC.

- Diferentemente da DLL do MFC regular vinculada estaticamente, esse tipo de DLL é vinculado dinamicamente à DLL do MFC (também conhecida como DLL compartilhada do MFC).

- A biblioteca de importação do MFC vinculada a esse tipo de DLL é a mesma usada para DLLs de extensão do MFC ou aplicativos usando a DLL do MFC: MFCxx (D). lib.

Uma DLL do MFC regular, vinculada dinamicamente ao MFC, tem os seguintes requisitos:

- Essas DLLs são compiladas com **_AFXDLL** definidas, assim como um executável que é vinculado DINAMICAMENTE à dll do MFC. Mas **_USRDLL** também é definido, assim como uma DLL comum do MFC que é vinculada ESTATICAMENTE ao MFC.

- Esse tipo de DLL deve criar uma `CWinApp`instância de uma classe derivada.

- Esse tipo de DLL usa o `DllMain` fornecido pelo MFC. Coloque todo o `InitInstance` código de inicialização específico da dll na função de membro e no `ExitInstance` código de encerramento no como em um aplicativo MFC normal.

Como esse tipo de DLL usa a versão da biblioteca de vínculo dinâmico do MFC, você deve definir explicitamente o estado atual do módulo como aquele para a DLL. Para fazer isso, use a macro [AFX_MANAGE_STATE](../mfc/reference/extension-dll-macros.md#afx_manage_state) no início de cada função exportada da dll.

as DLLs regulares do MFC devem `CWinApp`ter uma classe derivada e um único objeto dessa classe de aplicativo, assim como um aplicativo MFC. No entanto `CWinApp` , o objeto da dll não tem uma bomba principal de mensagem, assim como `CWinApp` o objeto de um aplicativo.

Observe que o `CWinApp::Run` mecanismo não se aplica a uma dll, pois o aplicativo possui a bomba principal de mensagem. Se sua DLL abre caixas de diálogo sem janela restrita ou tem uma janela de quadro principal própria, a bomba principal de mensagem do seu aplicativo deve chamar uma rotina exportada `CWinApp::PreTranslateMessage`por dll que chama.

Coloque toda a `CWinApp::InitInstance` inicialização específica da dll na função de membro como em um aplicativo MFC normal. A `CWinApp::ExitInstance` função de membro de `CWinApp` sua classe derivada é chamada da função MFC `DllMain` fornecida antes que a dll seja descarregada.

Você deve distribuir as DLLs compartilhadas MFCx0. dll e Msvcr * 0. dll (ou arquivos semelhantes) com seu aplicativo.

Uma DLL que é vinculada dinamicamente ao MFC também não pode ser vinculada estaticamente ao MFC. Os aplicativos são vinculados a DLLs regulares do MFC dinamicamente vinculadas ao MFC, assim como qualquer outra DLL.

Normalmente, os símbolos são exportados de uma DLL do MFC regular usando a interface C padrão. A declaração de uma função exportada de uma DLL do MFC regular é semelhante a esta:

```
extern "C" __declspec(dllexport) MyExportedFunction( );
```

Todas as alocações de memória em uma DLL do MFC regular devem permanecer dentro da DLL; a DLL não deve passar para ou receber do executável de chamada qualquer um dos seguintes:

- ponteiros para objetos MFC

- ponteiros para a memória alocada pelo MFC

Se você precisar fazer qualquer uma das opções acima, ou se precisar passar objetos derivados do MFC entre o executável de chamada e a DLL, deverá criar uma DLL de extensão do MFC.

É seguro passar ponteiros para a memória que foram alocados pelas bibliotecas de tempo de execução C entre um aplicativo e uma DLL somente se você fizer uma cópia dos dados. Você não deve excluir nem redimensionar esses ponteiros nem usá-los sem fazer uma cópia da memória.

Ao criar uma DLL do MFC regular que vincula dinamicamente ao MFC, você precisa usar a macro [AFX_MANAGE_STATE](../mfc/reference/extension-dll-macros.md#afx_manage_state) para alternar corretamente o estado do módulo MFC. Isso é feito adicionando a seguinte linha de código ao início das funções exportadas da DLL:

```
AFX_MANAGE_STATE(AfxGetStaticModuleState( ))
```

A macro **AFX_MANAGE_STATE** não deve ser usada em DLLs do MFC regulares que se vinculam ESTATICAMENTE ao MFC ou às DLLs de extensão do MFC. Para obter mais informações, consulte [Gerenciando os dados de estado dos módulos do MFC](../mfc/managing-the-state-data-of-mfc-modules.md).

Para obter um exemplo de como escrever, compilar e usar uma DLL do MFC regular, consulte o exemplo de [DLLScreenCap](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/DllScreenCap). Para obter mais informações sobre DLLs do MFC regulares que se vinculam dinamicamente ao MFC, consulte a seção "Convertendo DLLScreenCap para vincular dinamicamente com a DLL do MFC" no resumo do exemplo.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Inicializar DLLs regulares do MFC](run-time-library-behavior.md#initializing-regular-dlls)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [O módulo declara uma DLL de MFC regular dinamicamente vinculada ao MFC](module-states-of-a-regular-dll-dynamically-linked-to-mfc.md)

- [Gerenciando os dados de estado dos módulos do MFC](../mfc/managing-the-state-data-of-mfc-modules.md)

- [Usando DLLs de extensão do banco de dados, OLE e sockets do MFC em DLLs comuns do MFC](using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)

- [Usando o MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)

## <a name="see-also"></a>Confira também

[Tipos de DLLs](kinds-of-dlls.md)
