---
title: "Visão geral de possíveis problemas de atualização (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 2c99a8cb-098f-4a9d-bf2c-b80fd06ace43
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1f1a727920ffe5e79bd62fd877e191dc6f6f3cc3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="overview-of-potential-upgrade-issues-visual-c"></a>Visão geral de possíveis problemas de atualização (Visual C++)
Ao longo dos anos, o compilador do Visual C++ passou por muitas alterações, juntamente com as alterações na própria linguagem C++, a Biblioteca Padrão C++, o CRT (Tempo de Execução de C) e outras bibliotecas como MFC e ATL. Como resultado, ao atualizar um aplicativo de uma versão anterior do Visual C++ você pode encontrar erros e avisos de compilador e vinculador no código previamente compilado corretamente. Quanto mais antiga a base de código original, maior o potencial para tais erros. Esta visão geral resume as classes mais comuns dos problemas que você pode encontrar e fornece links para informações mais detalhadas.  
  
 Observação: no passado, era recomendável que as atualizações que abrangiam várias versões do Visual Studio fossem realizadas incrementalmente uma versão por vez. Essa abordagem não é mais recomendada. Descobrimos que quase sempre é mais simples atualizar para a versão mais recente do Visual Studio independentemente de quão antiga é a base de código.  
  
 As perguntas ou comentários sobre o processo de atualização podem ser enviados para vcupgrade na microsoft.  
  
## <a name="library-and-toolset-dependencies"></a>Dependências de biblioteca e o conjunto de ferramentas  
 Ao atualizar um aplicativo para uma nova versão do compilador do Visual C++, é altamente aconselhável e em muitos casos necessário também atualizar todas as bibliotecas e DLLs vinculadas ao aplicativo. Isso exige que você tenha acesso ao código-fonte ou que o fornecedor da biblioteca possa fornecer novos arquivos binários compilados com a mesma versão principal do compilador do Visual C++. Se uma dessas condições for verdadeira, você poderá ignorar esta seção, que lida com os detalhes de compatibilidade do binário. Se nenhuma delas for o caso, talvez você não consiga usar as bibliotecas no aplicativo atualizado. As informações nesta seção o ajudarão a entender se você pode prosseguir com a atualização.  
  
### <a name="toolset"></a>Conjunto de Ferramentas  
 Os formatos de arquivo obj e lib são bem definidos e raramente mudam. Às vezes, são feitas adições a esses formatos de arquivo, mas essas adições geralmente não afetam a capacidade de conjuntos de ferramentas mais recentes de consumir arquivos-objeto e bibliotecas produzidos por conjuntos de ferramentas mais antigos. A única grande exceção aqui é se você compilar usando /GL (Geração de Código Durante o Tempo de Vinculação/Otimização do Programa Inteiro). Se você compilar usando /GL, a arquivo-objeto resultante poderá ser vinculado apenas usando o mesmo conjunto de ferramentas que foi usado para gerá-lo. Portanto, se você gerar um arquivo-objeto com /GL e usando o compilador do Visual Studio 2017 (v141), deverá vinculá-lo usando o vinculador do Visual Studio 2017 (v141). Isso ocorre porque as estruturas de dados internas dentro dos objetos /GL não estão estáveis entre as versões principais do conjunto de ferramentas e os conjuntos de ferramentas mais novos não entendem os formatos de dados mais antigos.  
  
 O C++ não tem uma ABI (interface binária de aplicativo) estável. O Visual C++ mantém uma ABI estável para todas as versões secundárias de uma versão. Por exemplo, o Visual Studio 2017 e todas as atualizações são compatíveis em relação ao binário. Mas a ABI não é necessariamente compatível com as versões principais do Visual C++ (exceto 2015 e 2017, que _são_ compatíveis em relação ao binário). Ou seja, podemos fazer alterações significativas no layout de tipo do C++, na decoração de nome, no tratamento de exceções e outras partes da ABI do C++. Portanto, se você tiver um arquivo-objeto que tenha símbolos externos com vinculação C++, esse arquivo-objeto poderá não vincular corretamente com arquivos-objeto produzidos com uma versão principal diferente do conjunto de ferramentas do Visual C++. Observe que aqui, "pode não funcionar" tem muitos resultados possíveis: o link pode falhar totalmente (por exemplo, se a decoração de nome foi alterada), o link pode ter êxito e as coisas podem não funcionar em tempo de execução (por exemplo, se o layout do tipo foi alterado) ou as coisas podem funcionar em muitos casos e não haverá nada errado. Observe também que embora a ABI do C++ não seja estável, a ABI do C e o subconjunto da ABI do C++ necessárias para COM são estáveis.  
  
### <a name="libraries"></a>Libraries  

 Se você compilar um arquivo de origem usando uma versão específica de cabeçalhos de bibliotecas do Visual C++ (#incluindo os cabeçalhos), o arquivo-objeto resultante deverá ser vinculado com a mesma versão das bibliotecas do Visual C++. Portanto, por exemplo, se seu arquivo de origem for compilado com o Visual Studio de 2017 \<immintrin.h>, você deverá vincular com a biblioteca vcruntime do Visual Studio 2017. Da mesma forma, se seu arquivo de origem for compilado com o Visual Studio de 2017 \<iostream>, você deverá vincular à biblioteca C++ padrão do Visual Studio 2017, msvcprt. Não há suporte para a mistura e combinação.  
  
 Para a Biblioteca Padrão C++, a mistura e combinação foi explicitamente proibida por meio do uso de `#pragma detect_mismatch` nos cabeçalhos padrão desde o Visual Studio 2010. Se você tentar vincular os arquivos-objeto incompatíveis ou tentar vincular com a biblioteca de padrão incorreta, o link falhará.  
  
 Para o CRT, a mistura e combinação nunca teve suporte, mas muitas vezes isso funcionava, pelo menos até o Visual Studio 2015 e o CRT Universal, porque a superfície da API não mudou muito ao longo do tempo. A CRT Universal interrompeu a compatibilidade com versões anteriores para que no futuro possamos manter a compatibilidade com versões anteriores. Em outras palavras, não temos planos de introduzir novos binários de CRT Universal com versão no futuro. Em vez disso, o CRT Universal existente agora é atualizado no local.  
  
 Para proporcionar compatibilidade de link parcial com arquivos-objeto (e bibliotecas) compilados com versões mais antigas dos cabeçalhos do Tempo de Execução de C da Microsoft, fornecemos uma biblioteca, legacy_stdio_definitions.lib, com o Visual Studio 2015 e posterior. Essa biblioteca fornece símbolos de compatibilidade para a maioria das exportações de funções e dados que foram removidas do CRT Universal. O conjunto de símbolos de compatibilidade fornecido por legacy_stdio_definitions.lib é suficiente para atender a maioria das dependências, incluindo todas as dependências em bibliotecas no SDK do Windows. No entanto, há alguns símbolos que foram removidos do CRT Universal para os quais não é possível fornecer símbolos de compatibilidade como este. Esses símbolos incluem algumas funções (por exemplo, \_\_iob\_func) e as exportações de dados (por exemplo, \_\_imp\_\_\_iob, \_\_imp\_\_\_pctype, \_\_imp\_\_\_mb\_cur\_max).  
  
 Se você tiver uma biblioteca estática que foi compilada com uma versão mais antiga dos cabeçalhos de Tempo de Execução de C, recomendamos as seguintes ações (nesta ordem):  
  
1.  Recompile a biblioteca estática usando o Visual C++ 2017 e os cabeçalhos de CRT Universal para dar suporte à vinculação com o CRT Universal. Essa é a opção com suporte total (e, portanto, a melhor).  
  
2.  Se você não puder (ou não quiser) recompilar a biblioteca estática, poderá tentar vincular com legacy_stdio_definitions.lib. Se ela atender às dependências de tempo de vinculação da biblioteca estática, você desejará testar completamente a biblioteca estática como ela é usada no binário para garantir que ela não será prejudicada por nenhuma das [alterações comportamentais que foram feitas no CRT Universal](visual-cpp-change-history-2003-2015.md#BK_CRT).  
  
3.  Se as dependências da biblioteca estática não forem atendidas pela legacy_stdio_definitions.lib ou se a biblioteca não funcionar com o CRT Universal devido às alterações comportamentais mencionadas anteriormente, recomendamos encapsular a biblioteca estática em uma DLL que pode ser vinculada à versão correta do Tempo de Execução de C da Microsoft. Por exemplo, se a biblioteca estática foi compilada usando o Visual C++ 2013, convém compilar essa DLL utilizando o Visual C++ 2013 e bibliotecas do Visual C++ 2013. Ao compilar a biblioteca em uma DLL, você encapsula os detalhes de implementação que é sua dependência em uma versão específica do Tempo de Execução de C da Microsoft. (Observe que você deve ter cuidado para que a interface da DLL não vaze detalhes de qual Tempo de Execução de C ela usa, por exemplo, retornando um ARQUIVO* pelo limite da DLL ou retornando um ponteiro alocado por malloc e esperando que o chamador o libere.)  
  
 O uso de vários CRTs em um único processo não é problemático em si (na verdade, a maioria dos processos acabará carregando várias DLLs de CRT, por exemplo, componentes do sistema operacional Windows dependerão de msvcrt.dll e o CLR dependerá de seu próprio CRT privado). Os problemas surgem quando você mistura o estado de diferentes CRTs. Por exemplo, você não deve alocar memória usando msvcr110.dll!malloc e tentar desalocar essa memória usando msvcr120.dll!free e você não deve tentar abrir um ARQUIVO usando msvcr110!fopen e tentar ler esse ARQUIVO usando msvcr120!fread. Desde que você não misture o estado de CRTs diferentes, você pode ter com segurança vários CRTs carregados em um único processo.  
  
 Para obter mais informações, consulte [Upgrade your code to the Universal CRT](upgrade-your-code-to-the-universal-crt.md) (Atualizar seu código para o CRT Universal).  
  
## <a name="errors-due-to-project-settings"></a>Erros devido a configurações de projeto  
 Para começar o processo de atualização, basta abrir um projeto/solução/espaço de trabalho mais antigo na versão mais recente do Visual Studio. O Visual Studio criará um novo projeto com base nas configurações do projeto antigo. Se o projeto antigo tiver uma biblioteca ou incluir caminhos que são embutidos em código para locais não padrão, será possível que os arquivos nesses caminhos não sejam visíveis para o compilador quando o projeto usar as configurações padrão. Para obter mais informações, consulte [Linker OutputFile setting](porting-guide-spy-increment.md#linker_output_settings) (Configuração de OutputFile do vinculador).  
  
 Em geral, agora é um bom momento para organizar o código do projeto adequadamente para simplificar a manutenção do projeto e ajudar a fazer com que seu código atualizado compile o mais rápido possível. Se seu código-fonte já estiver bem organizado e seu projeto mais antigo for compilado com o Visual Studio 2010 ou posterior, você poderá editar manualmente o novo arquivo de projeto para dar suporte à compilação no compilador antigo e no novo. O exemplo a seguir mostra como compilar para Visual Studio 2015 e Visual Studio 2017:  
  
```  
<PlatformToolset Condition="'$(VisualStudioVersion)'=='14.0'">v140</PlatformToolset>  
<PlatformToolset Condition="'$(VisualStudioVersion)'=='15.0'">v141</PlatformToolset>   
```  
  
### <a name="lnk2019-unresolved-external"></a>LNK2019: externo não resolvido  
 Para os símbolos não resolvidos, você precisará corrigir as configurações do projeto.  
  
-   Se o arquivo de origem estiver em um local não padrão, você adicionou o caminho para os diretórios de inclusão do projeto?  
  
-   Se o externo estiver definido em um arquivo .lib, você especificou o caminho do lib nas propriedades do projeto e a versão correta do arquivo .lib realmente está localizada lá?  
  
-   Você está tentando vincular a um arquivo .lib que foi compilado com uma versão diferente do Visual Studio? Nesse caso, consulte a seção anterior sobre dependências de biblioteca e o conjunto de ferramentas.  
  
-   Os tipos dos argumentos no site de chamada realmente coincidem com uma sobrecarga existente da função? Verifique se os tipos subjacentes de quaisquer typedefs na assinatura da função e no código que chama a função o que você espera que sejam.  
  
 Para solucionar problemas de erros de símbolo não resolvido, você pode tentar usar o dumpbin.exe para examinar os símbolos definidos em um binário. Experimente a seguinte linha de comando para exibir os símbolos definidos em uma biblioteca:  
  
```  
dumpbin.exe /LINKERMEMBER somelibrary.lib  
```  
  
### <a name="zcwchart-wchart-is-native-type"></a>/Zc:wchar_t (wchar_t é do tipo nativo)  
 (No Visual C++ 6.0 e versões anteriores, wchar_t não era implementado como um tipo interno, mas era declarado no wchar.h como um typedef para unsigned short.) O padrão C++ requer que wchar_t seja um tipo interno. Usar a versão typedef pode causar problemas de portabilidade. Se você atualizar de versões anteriores do Visual C++ e encontrar o erro C2664 do compilador porque o código está tentando converter implicitamente um wchar_t em unsigned short, recomendamos alterar o código para corrigir o erro, em vez de configurar /Zc:wchar_t-. Para obter mais informações, consulte [/Zc:wchar_t (wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md).  
  
### <a name="upgrading-with-the-linker-options-nodefaultlib-entry-and-noentry"></a>Atualizando com as opções de vinculador /NODEFAULTLIB, /ENTRY e /NOENTRY  
 A opção de vinculador /NODEFAULTLIB (ou a propriedade de vinculador Ignorar Todas as Bibliotecas Padrão) instrui o vinculador a não vincular automaticamente nas bibliotecas padrão como o CRT. Isso significa que cada biblioteca deve ser listada como entrada individualmente. Esta lista de bibliotecas é fornecida na propriedade Dependências Adicionais na seção Vinculador das Propriedades do Projeto.  
  
 Os projetos que usam essa opção apresentam um problema durante a atualização, porque os nomes de algumas das bibliotecas padrão foram alterados. Como cada biblioteca tem que ser listada na propriedade Dependências Adicionais ou na linha de comando do vinculador, você precisa atualizar a lista de bibliotecas para usar os nomes atuais.  
  
 A tabela a seguir mostra as bibliotecas cujos nomes foram alterados começando com o Visual Studio 2015. Para atualizar, você precisa substituir os nomes na primeira coluna pelos nomes na segunda coluna.  Algumas dessas bibliotecas são bibliotecas de importação, mas isso não importa.  
  
|||  
|-|-|  
|Se você estiver usando:|Precisará substitui-lo por:|  
|libcmt.lib|libucrt.lib, libvcruntime.lib|  
|libcmtd.lib|libucrtd.lib, libvcruntimed.lib|  
|msvcrt.lib|ucrt.lib, vcruntime.lib|  
|msvcrtd.lib|ucrtd.lib, vcruntimed.lib|  
  
 O mesmo problema se aplica também se você usar a opção /ENTRY ou a opção /NOENTRY, que também tem o efeito de ignorar as bibliotecas padrão.  
  
## <a name="errors-due-to-improved-language-conformance"></a>Erros devido à conformidade de linguagem aprimorada  
 O compilador do Visual C++ melhorou continuamente sua conformidade com o padrão C++ ao longo dos anos. O código compilado em versões anteriores do Visual C++ pode falhar ao ser compilado no Visual Studio 2017 porque o compilador sinaliza corretamente um erro que anteriormente ele ignorou ou permitiu explicitamente.  
  
 Por exemplo, a opção /Zc:forScope foi introduzida no início do histórico do Visual C++. Ela permite o comportamento não conforme para variáveis de loop. Essa opção foi preterida e deve ser removida em versões futuras. É altamente recomendável não usar essa opção ao atualizar seu código. Para obter mais informações, consulte [/Zc:forScope- is deprecated](porting-guide-spy-increment.md#deprecated_forscope) (/Zc:forScope- foi preterida).  
  
 Um exemplo de um erro do compilador comum que você pode ver ao atualizar é quando um argumento não const é passado para um parâmetro const. As versões mais antigas do Visual C++ nem sempre sinalizavam isso como um erro. Para obter mais informações, consulte [The compiler's more strict conversions](porting-guide-spy-increment.md#stricter_conversions) (As conversões mais restritas do compilador).  
  
 Para obter mais informações sobre aprimoramentos de compatibilidade específicos, consulte [Histórico de alterações do Visual C++ de 2003 – 2015](visual-cpp-change-history-2003-2015.md) e [Aprimoramentos de conformidade do C++ no Visual Studio 2017](../cpp-conformance-improvements-2017.md).  
  
## <a name="errors-involving-stdinth-integral-types"></a>Erros envolvendo os tipos integrais \<stdint.h>  
 O cabeçalho \<stdint.h> define typedefs e macros que, diferente dos tipos integrais internos, têm a garantia de ter um comprimento específico em todas as plataformas. Alguns exemplos são uint32_t e int64_t. O Visual C++ adicionou o \<stdint.h> no Visual Studio 2010. O código escrito antes de 2010 pode ter fornecido definições privadas para esses tipos e essas definições nem sempre são consistentes com as definições do \<stdint.h>.  
  
 Se o erro for C2371 e um tipo de stdint estiver envolvido, isso provavelmente significará que o tipo é definido em um cabeçalho em seu código ou em um arquivo de biblioteca de terceiros.  Ao atualizar, você deve eliminar quaisquer definições personalizadas dos tipos \<stdint.h>, mas primeiro compare as definições personalizadas às definições padrão atuais para garantir que você não está introduzindo novos problemas.  
  
 Você pode pressionar F12 **Ir para Definição** para ver onde o tipo em questão é definido.  
  
 A opção do compilador [/showIncludes](../build/reference/showincludes-list-include-files.md) pode ser útil aqui. Na caixa de diálogo Páginas de Propriedades do projeto, abra o **C/C++**, página **Avançada** e defina **Mostrar Inclusões** como **Sim**. Em seguida, recompile o projeto e veja a lista de #includes na janela de saída.  Cada cabeçalho é recuado sob o cabeçalho que o inclui.  
  
## <a name="errors-involving-crt-functions"></a>Erros envolvendo funções CRT  
 Foram feitas várias alterações no tempo de execução de C ao longo dos anos. Muitas versões seguras de funções foram adicionadas e algumas foram removidas. Além disso, conforme descrito anteriormente neste artigo, a implementação da Microsoft do CRT foi refatorada no Visual Studio 2015 em novos binários e arquivos .lib associados.  
  
 Se o erro envolve uma função CRT, pesquise o [Visual C++ change history 2003 – 2015](visual-cpp-change-history-2003-2015.md) (Histórico de alterações do Visual C++ de 2003 – 2015) ou [C++ conformance improvements in Visual Studio 2017](../cpp-conformance-improvements-2017.md) (Aprimoramentos de conformidade do C++ no Visual Studio 2017) para ver se esses tópicos contêm informações adicionais. Se o erro for LNK2019, externo não resolvido, verifique se que a função não foi removida. Caso contrário, se você tiver certeza de que a função ainda existe e que o código de chamada está correto, verifique se seu projeto usa /NODEFAULTLIB. Nesse caso, você precisa atualizar a lista de bibliotecas para que o projeto utiliza as novas bibliotecas (UCRT) universais. Consulte a seção acima sobre Biblioteca e dependências para obter mais informações.  
  
 Se o erro envolve printf ou scanf, certifique-se de que você não esteja definindo em particular qualquer função sem incluir stdio.h. Nesse caso, remova as definições particulares ou vincule a legacy_stdio_definitions.lib legacy_stdio_definitions.lib (Projeto &#124; Propriedades &#124; Vinculador &#124; Entrada de Vinculador). Se você estiver vinculado ao SDK do Windows 8.1 ou anterior, adicione legacy_stdio_definitions.lib.  
  
 Se o erro envolve argumentos de cadeia de caracteres de formato, provavelmente é porque o compilador é mais estrito sobre a aplicação do padrão. Consulte o histórico de alterações para obter mais informações. Preste atenção a quaisquer erros aqui, pois eles podem potencialmente representar um risco de segurança.  
  
## <a name="errors-due-to-changes-in-the-c-standard"></a>Erros devido a alterações no padrão C++  
 O padrão C++ em si evoluiu de maneiras que não são compatíveis com versões anteriores. A introdução no C++11 da semântica de transferência de recursos, novas palavras-chave e outras linguagens e recursos de biblioteca padrão pode potencialmente causar erros de compilador e até mesmo comportamentos de tempo de execução diferentes.  
  
 Por exemplo, um programa C++ antigo pode incluir o cabeçalho iostream.h. Esse cabeçalho foi preterido no início do histórico do C++ e eventualmente foi completamente removido do Visual C++. Nesse caso, você precisará usar \<iostream> e reescrever seu código. Para obter mais informações, consulte [Updating old iostreams code](porting-guide-spy-increment.md#updating_iostreams_code) (Atualizando o código antigo de iostreams).  
  
### <a name="c4838-narrowing-conversion-warning"></a>C4838: aviso de conversão de estreitamento  
 O padrão C++ agora especifica que as conversões de valores integrais sem sinal para com sinal são consideradas como conversões de estreitamento. O compilador do Visual C++ não gerava esse aviso antes do Visual Studio 2015. Você deve inspecionar cada ocorrência para verificar se o estreitamento não afeta a exatidão do seu código.  
  
## <a name="warnings-to-use-secure-crt-functions"></a>Avisos para usar funções CRT seguras  
 Ao longo dos anos, foram introduzidas versões seguras de funções de tempo de execução de C. Embora as versões antigas e não seguro ainda estejam disponíveis, é recomendável alterar o código para usar as versões seguras. O compilador emitirá um aviso para o uso das versões não seguras. Você pode optar por desabilitar ou ignorar esses avisos. Para desabilitar o aviso para todos os projetos na solução, abra **Exibir &#124; Gerenciador de Propriedades**, selecione todos os projetos para os quais deseja desabilitar o aviso, clique com o botão direito do mouse nos itens selecionados e escolha **Propriedades &#124; C/C++ &#124; Avançado &#124; Desabilita Avisos Específicos**. Clique na seta suspensa e, em seguida, clique em Editar. Digite 4996 na caixa de texto. (Não inclua o prefixo "C".) Para obter mais informações, consulte [Porting to use the Secure CRT](porting-guide-spy-increment.md#porting_to_secure_crt) (Portabilidade para usar o CRT Seguro).  
  
## <a name="errors-due-to-changes-in-windows-apis-or-obsolete-sdks"></a>Erros devido a alterações nas APIs do Windows ou SDKs obsoletos  
 Ao longo dos anos, os tipos de dados e as APIs do Windows foram adicionados e às vezes alterados ou removidos. Além disso, outros SDKs que não pertenciam ao sistema operacional principal apareceram e desapareceram. Programas mais antigos, portanto, podem conter chamadas às APIs que não existem mais. Eles também podem conter chamadas às APIs em outros SDKs da Microsoft que não têm mais suporte.  Se você vir um erro que envolve uma API do Windows ou uma API de um SDK da Microsoft mais antigo, é possível que uma API tenha sido removida e/ou substituída por uma função mais recente e mais segura.  
  
 Para obter mais informações sobre o conjunto de APIs atual e os sistemas operacionais mínimos com suporte para uma API do Windows específica, consulte [Windows API Index](https://msdn.microsoft.com/en-us/library/ff818516\(v=vs.85\).aspx) (Índice de APIs do Windows) e navegue até a API em questão.  
  
### <a name="windows-version"></a>Versão do Windows  
 Ao atualizar um programa que usa a API do Windows, direta ou indiretamente, você precisará decidir a versão mínima do Windows para dar suporte. Na maioria dos casos o Windows 7 é uma boa opção. Para obter mais informações, consulte [Header file problems](porting-guide-spy-increment.md#header_file_problems) (Problemas de arquivo de cabeçalho). A macro WINVER define a versão mais antiga do Windows na qual programa é projetado para ser executado. Se o seu programa MFC definir WINVER como 0x0501 (Windows XP) você receberá um aviso porque o MFC não dá mais suporte ao XP, embora o compilador em si tenha um modo XP.  
  
 Para obter mais informações, consulte [Updating the Target Windows Version](porting-guide-spy-increment.md#updating_winver) (Atualizando a versão de destino do Windows) e [More outdated header files](porting-guide-spy-increment.md#outdated_header_files) (Mais arquivos de cabeçalho desatualizados).  
  
## <a name="atl--mfc"></a>ATL / MFC  
 A ATL e o MFC são APIs relativamente estáveis, mas as alterações são feitas ocasionalmente. Consulte o [Histórico de alterações do Visual C++ de 2003 – 2015](visual-cpp-change-history-2003-2015.md) para obter mais informações e [Novidades para o Visual C++ no Visual Studio 2017](../what-s-new-for-visual-cpp-in-visual-studio.md) e [Aprimoramentos de conformidade do C++ no Visual Studio 2017](../cpp-conformance-improvements-2017.md).  
  
### <a name="lnk-2005-dllmain12-already-defined-in-msvcrtdlib"></a>2005 LNK _DllMain@12 já definido no MSVCRTD.lib  
 Esse erro pode ocorrer em aplicativos MFC. Ele indica um problema de ordenação entre a biblioteca CRT e a biblioteca MFC. O MFC deve ser vinculado primeiro para que ele forneça os operadores new e delete. Para corrigir o erro, use a opção /NODEFAULTLIB para ignorar essas bibliotecas padrão: MSVCRTD.lib e mfcs140d.lib. Em seguida, adicione essas mesmas bibliotecas como dependências adicionais.  
  
## <a name="32-vs-64-bit"></a>32 bits vs 64 bits  
 Se seu código original for compilado para sistemas de 32 bits, você terá a opção de criar uma versão de 64 bits em vez de ou além de um novo aplicativo de 32 bits. Em geral, você deve fazer seu programa compilar no modo de 32 bits primeiro e então tentar o de 64 bits. O build para 64 bits é simples, mas em alguns casos ela pode revelar bugs que foram ocultados pelos builds de 32 bits.  
  
 Além disso, você deve estar atento a possíveis problemas de tempo de compilação e tempo de execução relacionados ao tamanho do ponteiro, valores de tempo e tamanho e especificadores de formato nas funções printf e scanf. Para obter mais informações, consulte [Configurar o Visual C++ para destinos x64 de 64 bits](../build/configuring-programs-for-64-bit-visual-cpp.md) e [Problemas comuns de migração de 64 bits do Visual C++](../build/common-visual-cpp-64-bit-migration-issues.md). Para obter dicas adicionais de migração, consulte [Programming Guide for 64-bit Windows](https://msdn.microsoft.com/library/windows/desktop/bb427430\(v=vs.85\).aspx) (Guia de programação para Windows de 64 bits).  
  
## <a name="unicode-vs-mbcsascii"></a>Unicode vs MBCS/ASCII  
 Antes de o Unicode ser padronizado, muitos programas usavam o MBCS (Conjunto de Caracteres Multibyte) para representar os caracteres que não estavam incluídos no conjunto de caracteres ASCII. Em projetos do MFC mais antigos, o MBCS era a configuração padrão e ao atualizar tal programa, você verá avisos que recomendam usar o Unicode em vez disso. Você pode optar por desabilitar ou ignorar o aviso se decidir que a conversão para Unicode não vale a pena o custo de desenvolvimento. Para desabilitá-lo para todos os projetos na solução, abra **Exibir &#124; Gerenciador de Propriedades**, selecione todos os projetos para os quais deseja desabilitar o aviso, clique com o botão direito do mouse nos itens selecionados e escolha **Propriedades &#124; C/C++ &#124; Avançado &#124; Desabilita Avisos Específicos**. Clique na seta suspensa e, em seguida, clique em Editar. Digite 4996 na caixa de texto. (Não inclua o prefixo "C".)  
  
 Para obter mais informações, consulte [Porting from MBCS to Unicode](porting-guide-spy-increment.md#porting_to_unicode) (Portabilidade de MBCS para Unicode). Para obter informações gerais sobre MBCS vs. Unicode, consulte [Text and Strings in Visual C++](../text/text-and-strings-in-visual-cpp.md) (Texto e cadeias de caracteres no Visual C++) e [Internationalization](../c-runtime-library/internationalization.md) (Internacionalização).  
  
## <a name="see-also"></a>Consulte também  
 [Atualização de projetos de versões anteriores do Visual C++](upgrading-projects-from-earlier-versions-of-visual-cpp.md) [Aprimoramentos de conformidade do C++ no Visual Studio 2017](../cpp-conformance-improvements-2017.md)
