---
title: Instalar um ausente Microsoft Visual C++ Runtime DLL | Microsoft Docs
description: "Como localizar e instalar ausente DLLs de tempo de execução do Visual C++."
ms.date: 03/13/2018
ms.topic: article
dev_langs:
- C++
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 6410c9753577852989172121d01c9d768f5373b3
ms.sourcegitcommit: 9239c52c05e5cd19b6a72005372179587a47a8e4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2018
---
# <a name="install-a-missing-microsoft-visual-c-runtime-dll"></a>Instalar um ausente Microsoft Visual C++ Runtime DLL

Programas escritos usando o Microsoft Visual C++ geralmente requerem alguns arquivos adicionais de biblioteca de tempo de execução do Visual C++, ou DLLs, para executar. Esses runtime DLLs estão disponíveis em um *pacote redistribuível*, um programa de instalação de arquivo de biblioteca, para cada versão do Visual C++. O pacote redistribuível exigido por qualquer programa deve ser incluído pelo instalador. Se não for, às vezes, pode instalar um pacote redistribuível por conta própria e corrigir um erro de sistema quando você executar o programa.

Você pode informar que um programa está faltando um tempo de execução do Visual C++ DLL se você receber um erro do sistema ao iniciar o programa que diz algo como "o programa não pode iniciar porque VCRuntime140.dll está ausente do seu computador". Geralmente, esse problema pode ser corrigido pela desinstalação do programa e instalá-lo novamente. É altamente recomendável tentar esta etapa primeiro, antes de quaisquer outros possíveis correções.

Às vezes, o pacote redistribuível instalado por um programa está desatualizado. A Microsoft disponibiliza versões atualizadas do tempo de execução DLLs de tempos em tempos, endereço bugs e problemas de segurança. Para manter seu computador funcionando corretamente e com segurança, é aconselhável usar a atualização mais recente para qualquer DLL em tempo de execução. Verifique se há um instalador atualizado disponível para o programa, o que pode fornecer essa atualização para você. Se houver, em seguida, use o instalador atualizado para reinstalar seu programa.

Se reinstalar o programa não faz o erro do sistema desaparecer, em seguida, o instalador do programa pode ser interrompido ou corrompido, ou o tempo de execução DLLs em seu computador pode estar corrompido. Tente baixar uma nova cópia do instalador para o seu programa e usá-lo para reinstalar o primeiro. Se isso não funcionar, ou um instalador não está disponível, pode ser útil para verificar as instalações do Microsoft Visual C++ redistribuível no seu computador.

Esta tabela mostra uma lista de DLLs que são incluídos em um ou mais pacotes redistribuíveis, junto com links para baixar uma cópia do pacote redistribuível. Antes de baixar uma nova cópia de um pacote redistribuível, você deverá ver se você pode reparar uma instalação existente.

|DLL ausente  |Pacote redistribuível  |
|---------|---------|
|atl80.dll<br />msvcm80.dll<br />msvcp80.dll<br />msvcr80.dll<br />mfc80.dll<br />mfc80u.dll<br />mfcm80.dll<br />mfcm80u.dll|[Microsoft Visual C++ 2005 redistribuível (x86)](https://www.microsoft.com/en-us/download/details.aspx?id=5638)<br />[Pacote redistribuível do Microsoft Visual C++ 2005 (x64)](https://www.microsoft.com/en-us/download/details.aspx?id=18471)<br />[Atualização de segurança do Microsoft Visual C++ 2005 Service Pack 1 Redistributable Package MFC](https://www.microsoft.com/en-us/download/details.aspx?id=26347)|
|atl90.dll<br />msvcr90.dll<br />msvcm90.dll<br />msvcp90.dll<br />mfc90.dll<br />mfc90u.dll<br />mfcmifc80.dll<br />mfcm90.dll<br />mfcm90u.dll|[Microsoft Visual C++ 2008 redistribuível - x86](https://www.microsoft.com/en-us/download/details.aspx?id=5582)<br />[Microsoft Visual C++ 2008 redistribuível - x64](https://www.microsoft.com/en-us/download/details.aspx?id=2092)<br />[Atualização de segurança do Microsoft Visual C++ 2008 Service Pack 1 Redistributable Package MFC](https://www.microsoft.com/en-us/download/details.aspx?id=26368)|
|atl100.dll<br />msvcr100.dll<br />msvcp100.dll<br />msdia71.dll<br />vcomp100.dll<br />mfc100.dll<br />mfc100u.dll<br />mfcmifc80.dll<br />mfcm100.dll<br />mfcm100u.dll|[Microsoft Visual C++ 2010 x86 redistribuível](https://www.microsoft.com/en-us/download/details.aspx?id=8328)<br />[Microsoft Visual C++ 2010 x64 redistribuível](https://www.microsoft.com/en-us/download/details.aspx?id=13523)<br />[Atualização de segurança do Microsoft Visual C++ 2010 Service Pack 1 Redistributable Package MFC](https://www.microsoft.com/en-us/download/details.aspx?id=26999)|
|atl110.dll<br />msvcr110.dll<br />msvcp110.dll<br />mfc110.dll<br />mfc110u.dll<br />mfcmifc80.dll<br />mfcm110.dll<br />mfcm110u.dll<br />concrt110.dll<br />vccorlib110.dll<br />vcamp110.dll<br />vcomp110.dll|[Microsoft Visual C++ 2012 Redistributable (para Visual Studio 2012 atualização 4)](https://www.microsoft.com/en-us/download/details.aspx?id=30679)|
|msvcr120.dll<br />msvcp120.dll<br />mfc120.dll<br />mfc120u.dll<br />mfcmifc80.dll<br />mfcm120.dll<br />mfcm120u.dll<br />concrt120.dll<br />vccorlib120.dll<br />vcamp120.dll<br />vcomp120.dll|[Microsoft Visual C++ 2013 redistribuível (links para downloads individuais)](https://support.microsoft.com/en-us/help/3179560/update-for-visual-c-2013-and-visual-c-redistributable-package)<br />[Biblioteca MFC multibyte para Visual Studio 2013](https://www.microsoft.com/en-us/download/details.aspx?id=40770)<br />[Visual C++ 2013 em tempo de execução para aplicativos de Sideload Windows 8.1 (download de arquivos. zip)](http://download.microsoft.com/download/5/F/0/5F0F8404-9329-44A9-8176-ED6F7F746F25/VCLibs_Redist_Packages.zip)|
|vcruntime140.dll<br />vcruntime140_app.dll<br />msvcp140.dll<br />msvcp140_1.dll, etc.<br />mfc140.dll<br />mfc140u.dll<br />mfcmifc80.dll<br />mfcm140.dll<br />mfcm140u.dll<br />concrt140.dll<br />vccorlib140.dll<br />vcamp140.dll<br />vcomp140.dll|[Microsoft Visual C++ 2017 (x86) redistribuível](https://go.microsoft.com/fwlink/?LinkId=746571)<br />[Microsoft Visual C++ 2017 (x64) redistribuível](https://go.microsoft.com/fwlink/?LinkId=746572)|
|msvcr100_clr0400.dll<br />msvcr110_clr0400.dll<br />msvcr120_clr0400.dll|[Baixe o .NET Framework](https://www.microsoft.com/net/download/framework)|

### <a name="to-repair-an-existing-redistributable-package"></a>Para reparar um pacote redistribuível existente

1. Abra o painel de controle. No Windows 10, digite *painel de controle* na área de trabalho do controle de pesquisa na barra de tarefas e, em seguida, escolha **painel de controle** entre as possibilidades.

2. No painel de controle, escolha **programas** > **programas e recursos**. Selecione a versão do Microsoft Visual C++ redistribuível que corresponde à DLL que está ausente. Se um **alteração** botão aparece no topo da lista, escolha-o. Se for a única opção **desinstalação**, você não pode reparar esta versão do pacote redistribuível.

3. Escolha **reparo** na caixa de diálogo de instalação para o pacote redistribuível. Talvez seja necessário reinicializar o computador quando a reparação é concluída.