---
title: Opções de compilador e vinculador (C++/CX)
ms.date: 01/22/2017
ms.assetid: ecfadce8-3a3f-40cc-bb01-b4731f8d2fcb
ms.openlocfilehash: cc1964c57d6700995bb283c245e4c63c8e9e313b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62383354"
---
# <a name="compiler-and-linker-options-ccx"></a>Opções de compilador e vinculador (C++/CX)

Uma variável de ambiente C++opções do compilador /CX e opções do vinculador dão suporte a criação de aplicativos para o tempo de execução do Windows.

## <a name="library-path"></a>Caminho da biblioteca

A variável de ambiente %LIBPATH% especifica o caminho padrão para procurar por arquivos .winmd.

## <a name="compiler-options"></a>Opções do compilador

|Opção|Descrição|
|------------|-----------------|
|[/ZW](../build/reference/zw-windows-runtime-compilation.md)<br /><br /> /ZW:nostdlib|Habilita extensões de linguagem do tempo de execução do Windows.<br /><br /> O parâmetro `nostdlib` impede que o compilador use o caminho de pesquisa padrão e predefinido para encontrar arquivos de assembly e .winmd.<br /><br /> A opção **/ZW** do compilador especifica implicitamente as opções do compilador:<br /><br />-  **/FI** vccorlib.h, que força a inclusão do arquivo de cabeçalho vccorlib.h, que define vários tipos que são necessários para o compilador.<br />- [/Fu](../build/reference/fu-name-forced-hash-using-file.md) winmd, que força a inclusão do arquivo de metadados do Windows que é fornecido pelo sistema operacional e define vários tipos em tempo de execução do Windows.<br />-  **/FU** Platform.winmd, que força a inclusão do arquivo de metadados Platform.winmd, que é fornecido pelo compilador e que define a maioria dos tipos na família Platform de namespaces.|
|[/AI](../build/reference/ai-specify-metadata-directories.md) *dir*|Adiciona um diretório, que é especificado pelo parâmetro *dir* , para o demarcador de pesquisa usado pelo compilador para encontrar arquivos de assembly e .winmd.|
|**/FU**  *Arquivo*|Força a inclusão do módulo especificado ou do arquivo .winmd. Ou seja, você não precisa especificar `#using` *arquivo* no seu código-fonte. O compilador força automaticamente a inclusão de seu próprio arquivo de metadados do Windows, Platform.winmd.|
|/D "WINAPI_FAMILY=2"|Cria uma definição que permite o uso de um subconjunto do SDK do Win32 é compatível com o tempo de execução do Windows.|

## <a name="linker-options"></a>Opções do vinculador

|Opção|Descrição|
|------------|-----------------|
|/APPCONTAINER[:NO]|Marca o executável como executável (somente) no appcontainer.|
|/WINMD[:{NO&#124;ONLY}]|Emite um arquivo .winmd e um arquivo binário associado. Essa opção deve ser transmitida para o vinculador para que um .winmd seja emitido.<br /><br /> **NO**– Não emite um arquivo .winmd, mas emite um arquivo binário.<br /><br /> **ONLY**– Emite um arquivo .winmd, mas não emite um arquivo binário.|
|/WINMDFILE:*nomedoarquivo*|O nome do arquivo .winmd para emitir, em vez do nome de arquivo .winmd padrão. Se forem especificados vários nomes de arquivo na linha de comando, o sobrenome será usado.|
|/WINMDDELAYSIGN[:NO]|Parcialmente assina o arquivo .winmd e coloca a chave pública no binário.<br /><br /> **NO**– (Padrão) Não assinar o arquivo .winmd.<br /><br /> /WINMDDELAYSIGN não tem nenhum efeito a menos que /WINMDKEYFILE ou /WINMDKEYCONTAINER também seja especificado.|
|/WINMDKEYCONTAINER:*nome*|Especifica um contêiner de chave para assinar um assembly. O parâmetro *name* corresponde ao contêiner de chave usado para assinar o arquivo de metadados.|
|/WINMDKEYFILE:*nomedoarquivo*|Especifica uma chave ou um par de chaves para assinar o assembly. O parâmetro *filename* corresponde à chave usada para assinar o arquivo de metadados.|

### <a name="remarks"></a>Comentários

Quando você usa o **/ZW**, o compilador é vinculado automaticamente à versão DLL do CRT (Tempo de Execução do C). Vinculando a versão da biblioteca estática não é permitida, e qualquer uso de funções de CRT que não são permitidos em um aplicativo da plataforma Universal do Windows causará um erro de tempo de compilação.

## <a name="see-also"></a>Consulte também

[Como compilar aplicativos e bibliotecas](../cppcx/building-apps-and-libraries-c-cx.md)
