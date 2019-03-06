---
title: DLLs MFC regulares vinculadas dinamicamente ao MFC
ms.date: 11/04/2016
helpviewer_keywords:
- regular MFC DLLs [C++], dynamically linked to MFC
- AFX_MANAGE_STATE macro
- DLLs [C++], regular
- shared DLL versions [C++]
- dynamically linked DLLs [C++]
ms.assetid: b4f7ab92-8723-42a5-890e-214f4e29dcd0
ms.openlocfilehash: 548fbde379937ab4d915f08a43a8b865e071d688
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57413167"
---
# <a name="regular-mfc-dlls-dynamically-linked-to-mfc"></a>DLLs MFC regulares vinculadas dinamicamente ao MFC

Uma expressão de que DLL do MFC vinculada dinamicamente ao MFC é uma DLL que usa internamente o MFC e as funções exportadas na DLL podem ser chamadas por executáveis MFC ou não MFC. Como o nome descreve, esse tipo de DLL é criado usando a versão da biblioteca de vínculo dinâmico do MFC (também conhecido como a versão compartilhada do MFC). Funções normalmente são exportadas de uma DLL do MFC usando a interface padrão do C regular.

Você deve adicionar o `AFX_MANAGE_STATE` macro no início de todas as funções exportadas em DLLs MFC regulares que vincular dinamicamente ao MFC para definir o estado atual do módulo para aquele para a DLL. Isso é feito adicionando a seguinte linha de código para o início das funções exportadas da DLL:

```
AFX_MANAGE_STATE(AfxGetStaticModuleState( ))
```

Regular DLL do MFC, vinculada dinamicamente ao MFC tem os seguintes recursos:

- Isso é um novo tipo de DLL apresentada pelo Visual C++ 4.0.

- O executável do cliente pode ser escrito em qualquer linguagem compatível com o uso de DLLs (C, C++, Pascal, Visual Basic e assim por diante); ele não precisa ser um aplicativo do MFC.

- Diferentemente a DLL do MFC regulares vinculadas estaticamente, esse tipo de DLL é vinculado dinamicamente ao MFC DLL (também conhecido como a DLL do MFC compartilhado).

- A biblioteca de importação MFC vinculada a esse tipo de DLL é o mesmo usado para DLLs de extensão do MFC ou aplicativos que usam a DLL do MFC: . Lib de MFCxx (D).

Regular DLL do MFC, vinculada dinamicamente ao MFC tem os seguintes requisitos:

- Essas DLLs são compiladas com **_AFXDLL** definido, assim como um executável que está vinculado dinamicamente ao MFC DLL. Mas **usrdll** também é definida, assim como uma DLL MFC regular que está vinculado estaticamente ao MFC.

- Esse tipo de DLL deve instanciar um `CWinApp`-classe derivada.

- Esse tipo de DLL usa o `DllMain` fornecidas pelo MFC. Coloque todo código de inicialização específica de DLL na `InitInstance` código de função e encerramento de membro em `ExitInstance` como em um aplicativo MFC normal.

Como esse tipo de DLL usa a versão da biblioteca de vínculo dinâmico do MFC, você deve definir explicitamente o estado atual do módulo para aquele para a DLL. Para fazer isso, use o [AFX_MANAGE_STATE](../mfc/reference/extension-dll-macros.md#afx_manage_state) macro no início de todas as funções exportadas da DLL.

DLLs MFC regulares deve ter um `CWinApp`-derivado de classe e um único objeto dessa classe de aplicativo, assim como um aplicativo do MFC. No entanto, o `CWinApp` o objeto da DLL não tem uma bomba de mensagem principal, como faz o `CWinApp` objeto de um aplicativo.

Observe que o `CWinApp::Run` mecanismo não se aplica a uma DLL, porque o aplicativo que detém a bomba de mensagem principal. Se sua DLL abre caixas de diálogo sem janela restrita ou tem uma janela de quadro principal de seu próprio, bomba de mensagem principal do seu aplicativo deve chamar uma rotina de DLL exportada que chama `CWinApp::PreTranslateMessage`.

Coloque todos os inicialização específica de DLL no `CWinApp::InitInstance` função de membro, como em um aplicativo MFC normal. O `CWinApp::ExitInstance` função de membro de seu `CWinApp` classe derivada é chamado a partir de MFC fornecido `DllMain` funcionar antes que a DLL seja descarregada.

Você deve distribuir as DLLs compartilhadas MFCx0.dll e Msvcr*0.dll (ou arquivos semelhantes) com seu aplicativo.

Uma DLL que é vinculada dinamicamente ao MFC não é possível vincular também estaticamente ao MFC. Link de aplicativos para DLLs MFC regulares vinculadas dinamicamente ao MFC-lo assim como qualquer outro DLL.

Símbolos geralmente são exportados de uma DLL do MFC usando a interface padrão do C regular. A declaração de uma função exportada de uma DLL MFC regular é algo parecido com isto:

```
extern "C" __declspec(dllexport) MyExportedFunction( );
```

Todas as alocações de memória dentro de uma DLL MFC regular devem permanecer dentro da DLL; a DLL não deve passar para ou receber do executável chamado qualquer um dos seguintes:

- Ponteiros para objetos MFC

- Ponteiros para a memória alocada pelo MFC

Se você precisar fazer qualquer uma das opções acima, ou se você precisar passar objetos derivados do MFC entre o executável de chamada e a DLL, você deve criar uma DLL de extensão do MFC.

É seguro passar ponteiros de memória que foram alocados pelas bibliotecas de tempo de execução C entre um aplicativo e uma DLL somente se você fazer uma cópia dos dados. Não exclua ou redimensione esses ponteiros ou usá-los sem fazer uma cópia da memória.

Ao criar uma DLL MFC regular que dinamicamente vincula ao MFC, você precisa usar a macro [AFX_MANAGE_STATE](../mfc/reference/extension-dll-macros.md#afx_manage_state) para alternar o estado do módulo MFC corretamente. Isso é feito adicionando a seguinte linha de código para o início das funções exportadas da DLL:

```
AFX_MANAGE_STATE(AfxGetStaticModuleState( ))
```

O **AFX_MANAGE_STATE** macro não deve ser usada em DLLs MFC regulares vinculadas estaticamente ao MFC ou em DLLs de extensão do MFC. Para obter mais informações, consulte [Gerenciando os dados de estado dos módulos de MFC](../mfc/managing-the-state-data-of-mfc-modules.md).

Para obter um exemplo de como gravar, criar e usar uma DLL MFC regular, consulte a amostra [DLLScreenCap](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/DllScreenCap). Para obter mais informações sobre DLLs MFC regulares vinculadas dinamicamente ao MFC, consulte a seção intitulada "Convertendo DLLScreenCap para dinamicamente Link com a DLL do MFC" em resumo para o exemplo.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Inicializar dll normais do MFC](../build/run-time-library-behavior.md#initializing-regular-dlls)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Os estados de módulo de uma DLL MFC regular vinculada dinamicamente ao MFC](../build/module-states-of-a-regular-dll-dynamically-linked-to-mfc.md)

- [Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)

- [Usando banco de dados, OLE e DLLs de extensão de MFC de soquetes em DLLs MFC regulares](../build/using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)

- [Usando MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)

## <a name="see-also"></a>Consulte também

[Tipos de DLLs](../build/kinds-of-dlls.md)
