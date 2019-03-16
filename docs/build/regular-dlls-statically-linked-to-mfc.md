---
title: DLLs MFC regulares vinculadas estaticamente ao MFC
ms.date: 11/04/2016
helpviewer_keywords:
- regular MFC DLLs [C++]
- DLLs [C++], regular
- USRDLLs
- USRDLLs, statically linked to MFC
- statically linked DLLs [C++]
- regular MFC DLLs [C++], statically linked to MFC
ms.assetid: 2eed531c-726a-4b8a-b936-f721dc00a7fa
ms.openlocfilehash: 1f05b5e3c268935cf3161fb7184e04b3e3ea1446
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57815795"
---
# <a name="regular-mfc-dlls-statically-linked-to-mfc"></a>DLLs MFC regulares vinculadas estaticamente ao MFC

Uma expressão de que DLL do MFC vinculada estaticamente ao MFC é uma DLL que usa internamente o MFC e as funções exportadas na DLL podem ser chamadas por executáveis MFC ou não MFC. Como o nome descreve, esse tipo de DLL é criado usando a versão da biblioteca de vínculo estático do MFC. Funções normalmente são exportadas de uma DLL do MFC usando a interface padrão do C regular. Para obter um exemplo de como gravar, criar e usar uma DLL MFC regular, consulte a amostra [DLLScreenCap](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/DllScreenCap).

Observe que o termo USRDLL não é mais usada na documentação do Visual C++. Uma DLL MFC regular que está vinculado estaticamente ao MFC tem as mesmas características da antiga usrdll.

Uma DLL MFC regular, vinculadas estaticamente ao MFC, tem os seguintes recursos:

- O executável do cliente pode ser escrito em qualquer linguagem compatível com o uso de DLLs (C, C++, Pascal, Visual Basic e assim por diante); ele não precisa ser um aplicativo do MFC.

- A DLL pode vincular para as mesmas bibliotecas de vínculo estático MFC usadas por aplicativos. Não é uma versão separada das bibliotecas de vínculo estático para DLLs.

- Antes da versão 4.0 do MFC, USRDLLs fornecido no mesmo tipo de funcionalidade como DLLs MFC regulares vinculadas estaticamente ao MFC. A partir do Visual C++ versão 4.0, o termo USRDLL é obsoleto.

Uma DLL MFC regular, vinculadas estaticamente ao MFC, tem os seguintes requisitos:

- Esse tipo de DLL deve instanciar uma classe derivada de `CWinApp`.

- Esse tipo de DLL usa o `DllMain` fornecidas pelo MFC. Coloque todo código de inicialização específica de DLL na `InitInstance` código de função e encerramento de membro em `ExitInstance` como em um aplicativo MFC normal.

- Embora o termo USRDLL está obsoleto, você ainda deve definir "**usrdll**" na linha de comando do compilador. Essa definição determina quais declarações é retirada do arquivos de cabeçalho MFC.

DLLs MFC regulares deve ter um `CWinApp`-derivado de classe e um único objeto dessa classe de aplicativo, assim como um aplicativo do MFC. No entanto, o `CWinApp` o objeto da DLL não tem uma bomba de mensagem principal, como faz o `CWinApp` objeto de um aplicativo.

Observe que o `CWinApp::Run` mecanismo não se aplica a uma DLL, porque o aplicativo que detém a bomba de mensagem principal. Se a DLL abre caixas de diálogo sem janela restrita ou tem uma janela de quadro principal de seu próprio, bomba de mensagem principal do aplicativo deve chamar uma rotina exportada pela DLL que por sua vez chama o `CWinApp::PreTranslateMessage` a função de membro de objeto de aplicativo da DLL.

Para obter um exemplo dessa função, consulte o exemplo DLLScreenCap.

Símbolos geralmente são exportados de uma DLL do MFC usando a interface padrão do C regular. A declaração de uma função exportada de uma DLL MFC regular seria algo parecido com isto:

```
extern "C" __declspec(dllexport) MyExportedFunction( );
```

Todas as alocações de memória dentro de uma DLL MFC regular devem permanecer dentro da DLL; a DLL não deve passar para ou receber do executável chamado qualquer um dos seguintes:

- Ponteiros para objetos MFC

- Ponteiros para a memória alocada pelo MFC

Se você precisar executar qualquer uma das opções acima ou precisar passar objetos derivados do MFC entre o executável de chamada e a DLL, você deve criar uma DLL de extensão do MFC.

É seguro passar ponteiros de memória que foram alocados pelas bibliotecas de tempo de execução C entre um aplicativo e uma DLL somente se você fazer uma cópia dos dados. Não exclua ou redimensione esses ponteiros ou usá-los sem fazer uma cópia da memória.

Uma DLL que está vinculada estaticamente ao MFC também dinamicamente não é possível vincular às DLLs do MFC compartilhado. Uma DLL que está vinculada estaticamente ao MFC dinamicamente está associada a um aplicativo assim como qualquer DLL; vincular aplicativos a ele, assim como qualquer outro DLL.

As bibliotecas de vínculo estático padrão do MFC são nomeadas de acordo com a convenção descrita em [convenções de nomenclatura para DLLs MFC](../mfc/mfc-library-versions.md#mfc-static-library-naming-conventions). No entanto, com o MFC versão 3.0 e posterior, não é necessário especificar manualmente para o vinculador a versão da biblioteca MFC que serem vinculados no. Em vez disso, os arquivos de cabeçalho MFC determinam automaticamente a versão correta da biblioteca MFC para vincular em pré-processador com base em define, como  **\_DEBUG** ou **Unicode**. Os arquivos de cabeçalho MFC adicionar diretivas /DEFAULTLIB instruindo o vinculador para vincular-se em uma versão específica da biblioteca MFC.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Inicializar dll normais do MFC](run-time-library-behavior.md#initializing-regular-dlls)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Usando MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)

- [Usando banco de dados, OLE e DLLs de extensão de MFC de soquetes em DLLs MFC regulares](using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)

- [Criando uma DLL MFC](../mfc/reference/mfc-dll-wizard.md)

- [DLLs MFC regulares vinculadas dinamicamente ao MFC](regular-dlls-dynamically-linked-to-mfc.md)

- [DLLs de extensão de MFC](extension-dlls-overview.md)

## <a name="see-also"></a>Consulte também

[Tipos de DLLs](kinds-of-dlls.md)
