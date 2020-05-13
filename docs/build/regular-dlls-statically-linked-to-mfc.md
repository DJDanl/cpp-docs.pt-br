---
title: DLLs regulares do MFC vinculadas estaticamente ao MFC
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
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62314774"
---
# <a name="regular-mfc-dlls-statically-linked-to-mfc"></a>DLLs regulares do MFC vinculadas estaticamente ao MFC

Uma DLL do MFC regular vinculada estaticamente ao MFC é uma DLL que usa o MFC internamente, e as funções exportadas na DLL podem ser chamadas por executáveis MFC ou não MFC. Como o nome descreve, esse tipo de DLL é criado usando a versão da biblioteca de links estáticos do MFC. Normalmente, as funções são exportadas de uma DLL do MFC regular usando a interface C padrão. Para obter um exemplo de como escrever, compilar e usar uma DLL do MFC regular, consulte o exemplo de [DLLScreenCap](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/DllScreenCap).

Observe que o termo USRDLL não é mais usado na documentação do Visual C++. Uma DLL do MFC regular que é vinculada estaticamente ao MFC tem as mesmas características que o USRDLL anterior.

Uma DLL do MFC regular, vinculada estaticamente ao MFC, tem os seguintes recursos:

- O executável do cliente pode ser escrito em qualquer linguagem que dê suporte ao uso de DLLs (C, C++, Pascal, Visual Basic e assim por diante); Não precisa ser um aplicativo MFC.

- A DLL pode ser vinculada às mesmas bibliotecas de vínculos estáticos do MFC usadas pelos aplicativos. Não há mais uma versão separada das bibliotecas de vínculo estático para DLLs.

- Antes da versão 4,0 do MFC, o USRDLLs fornecia o mesmo tipo de funcionalidade que as DLLs comuns do MFC vinculadas estaticamente ao MFC. A partir da versão Visual C++ 4,0, o termo USRDLL é obsoleto.

Uma DLL do MFC regular, vinculada estaticamente ao MFC, tem os seguintes requisitos:

- Esse tipo de DLL deve instanciar uma classe derivada `CWinApp`de.

- Esse tipo de DLL usa o `DllMain` fornecido pelo MFC. Coloque todo o `InitInstance` código de inicialização específico da dll na função de membro e no `ExitInstance` código de encerramento no como em um aplicativo MFC normal.

- Embora o termo USRDLL seja obsoleto, você ainda deve definir "**_USRDLL**" na linha de comando do compilador. Essa definição determina quais declarações são extraídas dos arquivos de cabeçalho do MFC.

as DLLs regulares do MFC devem `CWinApp`ter uma classe derivada e um único objeto dessa classe de aplicativo, assim como um aplicativo MFC. No entanto `CWinApp` , o objeto da dll não tem uma bomba principal de mensagem, assim como `CWinApp` o objeto de um aplicativo.

Observe que o `CWinApp::Run` mecanismo não se aplica a uma dll, pois o aplicativo possui a bomba principal de mensagem. Se a DLL abrir caixas de diálogo sem janela restrita ou tiver um quadro principal da sua própria, a bomba principal da mensagem do aplicativo deverá chamar uma rotina exportada pela DLL que, `CWinApp::PreTranslateMessage` por sua vez, chama a função membro do objeto de aplicativo da dll.

Para obter um exemplo dessa função, consulte o exemplo DLLScreenCap.

Normalmente, os símbolos são exportados de uma DLL do MFC regular usando a interface C padrão. A declaração de uma função exportada de uma DLL do MFC regular seria semelhante a esta:

```
extern "C" __declspec(dllexport) MyExportedFunction( );
```

Todas as alocações de memória em uma DLL do MFC regular devem permanecer dentro da DLL; a DLL não deve passar para ou receber do executável de chamada qualquer um dos seguintes:

- Ponteiros para objetos MFC

- Ponteiros para a memória alocada pelo MFC

Se precisar fazer qualquer uma das opções acima ou precisar passar objetos derivados do MFC entre o executável de chamada e a DLL, você deverá criar uma DLL de extensão do MFC.

É seguro passar ponteiros para a memória que foram alocados pelas bibliotecas de tempo de execução C entre um aplicativo e uma DLL somente se você fizer uma cópia dos dados. Você não deve excluir nem redimensionar esses ponteiros nem usá-los sem fazer uma cópia da memória.

Uma DLL que é vinculada estaticamente ao MFC também não pode ser vinculada dinamicamente às DLLs do MFC compartilhadas. Uma DLL que é vinculada estaticamente ao MFC é vinculada dinamicamente a um aplicativo, assim como qualquer outra DLL; os aplicativos são vinculados a ele, assim como qualquer outra DLL.

As bibliotecas de links estáticos do MFC padrão são nomeadas de acordo com a Convenção descrita em [convenções de nomenclatura para DLLs do MFC](../mfc/mfc-library-versions.md#mfc-static-library-naming-conventions). No entanto, com o MFC versão 3,0 e posteriores, não é mais necessário especificar manualmente para o vinculador a versão da biblioteca do MFC na qual você deseja vincular. Em vez disso, os arquivos de cabeçalho do MFC determinam automaticamente a versão correta da biblioteca do MFC para vincular com base em definições de pré-processador, como ** \_Debug** ou **_UNICODE**. Os arquivos de cabeçalho do MFC adicionam diretivas/DEFAULTLIB instruindo o vinculador a vincular em uma versão específica da biblioteca do MFC.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Inicializar DLLs regulares do MFC](run-time-library-behavior.md#initializing-regular-dlls)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Usando o MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)

- [Usando DLLs de extensão do banco de dados, OLE e sockets do MFC em DLLs comuns do MFC](using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)

- [Criando uma DLL do MFC](../mfc/reference/mfc-dll-wizard.md)

- [DLLs regulares do MFC vinculadas dinamicamente ao MFC](regular-dlls-dynamically-linked-to-mfc.md)

- [DLLs de extensão do MFC](extension-dlls-overview.md)

## <a name="see-also"></a>Confira também

[Tipos de DLLs](kinds-of-dlls.md)
