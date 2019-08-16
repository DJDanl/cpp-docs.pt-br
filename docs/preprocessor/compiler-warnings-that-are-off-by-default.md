---
title: Avisos de compilador desativados por padrão
ms.date: 05/30/2018
helpviewer_keywords:
- warnings, compiler
- cl.exe compiler, setting options
ms.assetid: 69809cfb-a38a-4035-b154-283a61938df8
ms.openlocfilehash: 1a95153f3cefd2bcfcae6ebb297a7c6b52944f82
ms.sourcegitcommit: d3829ae0c3db909f96057755a80665f5ea4896ea
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/16/2019
ms.locfileid: "69550471"
---
# <a name="compiler-warnings-that-are-off-by-default"></a>Avisos de compilador desativados por padrão

O compilador dá suporte a avisos desativados por padrão, porque a maioria dos desenvolvedores não os acha úteis. Em alguns casos, eles avisam sobre uma escolha estilístico ou sobre linguagens comuns em código mais antigo. Outros avisos são sobre o uso de uma extensão da Microsoft para o idioma. Em outros casos, eles indicam uma área em que os programadores geralmente fazem suposições incorretas, o que pode levar a um comportamento inesperado ou indefinido. Se habilitada, alguns desses avisos podem aparecer muitas vezes em cabeçalhos de biblioteca. As bibliotecas de tempo de execução C++ C e as bibliotecas padrão destinam-se a emitir somente avisos no nível de aviso [/W4](../build/reference/compiler-option-warning-level.md).

## <a name="enable-warnings-that-are-off-by-default"></a>Habilitar avisos que estão desativados por padrão

Você pode habilitar os avisos que normalmente estão desativados por padrão usando uma das seguintes opções:

- **aviso de #pragma (padrão:** *warning_number* **)**

   O aviso especificado (*warning_number*) está habilitado em seu nível padrão. A documentação para o aviso contém o nível padrão do aviso.

- **#pragma warning(** *warning_level* **:** *warning_number* **)**

   O aviso especificado (*warning_number*) está habilitado no nível especificado (*warning_level*).

- [/Wall](../build/reference/compiler-option-warning-level.md)

   `/Wall` habilita todos os avisos que são desativados por padrão. Se você usar essa opção, poderá desativar os avisos individuais usando a opção [/WD](../build/reference/compiler-option-warning-level.md) .

- [/w*Lnnnn*](../build/reference/compiler-option-warning-level.md)

   Essa opção habilita o aviso *nnnn* no nível *L*.

## <a name="warnings-that-are-off-by-default"></a>Avisos que estão desativados por padrão

Os avisos a seguir são desativados por padrão no Visual Studio 2015 e versões posteriores:

|||
|-|-|
|[C4061](../error-messages/compiler-warnings/compiler-warning-level-4-c4061.md) (nível 4)|o enumerador '*Identifier*' em uma opção de enumeração '*Enumeration*' não é manipulado explicitamente por um rótulo case|
|[C4062](../error-messages/compiler-warnings/compiler-warning-level-4-c4062.md) (nível 4)|o enumerador '*Identifier*' em uma opção de enumeração '*Enumeration*' não é tratado|
| [C4165](../error-messages/compiler-warnings/compiler-warning-level-1-c4165.md) (nível 1) | ' HRESULT ' está sendo convertido em ' bool '; Tem certeza de que deseja? |
| [C4191](../error-messages/compiler-warnings/compiler-warning-level-3-c4191.md) (nível 3)|'*Operator*': conversão não segura de '*type_of_expression*' para '*type_required*'|
|[C4242](../error-messages/compiler-warnings/compiler-warning-level-4-c4242.md) (nível 4)|'*Identifier*': conversão de '*type1*' para '*type2*', possível perda de dados|
|[C4254](../error-messages/compiler-warnings/compiler-warning-level-4-c4254.md) (nível 4)|'*Operator*': conversão de '*type1*' para '*type2*', possível perda de dados|
|[C4255](../error-messages/compiler-warnings/compiler-warning-level-4-c4255.md) (nível 4)|'*Function*': nenhum protótipo de função fornecido: convertendo ' () ' para ' (void) '|
|[C4263](../error-messages/compiler-warnings/compiler-warning-level-4-c4263.md) (nível 4)|'*Function*': a função membro não substitui nenhuma função membro virtual de classe base|
|[C4264](../error-messages/compiler-warnings/compiler-warning-level-1-c4264.md) (nível 1)|'*virtual_function*': nenhuma substituição disponível para função membro virtual da base '*Class*'; a função está oculta|
|[C4265](../error-messages/compiler-warnings/compiler-warning-level-3-c4265.md) (nível 3)|'*Class*': classe tem funções virtuais, mas destruidor não é virtual|
|[C4266](../error-messages/compiler-warnings/compiler-warning-level-4-c4266.md) (nível 4)|'*Function*': nenhuma substituição disponível para função membro virtual da base '*Type*'; a função está oculta|
|[C4287](../error-messages/compiler-warnings/compiler-warning-level-3-c4287.md) (nível 3)|'*Operator*': incompatibilidade de constante não assinada/negativa|
|[C4289](../error-messages/compiler-warnings/compiler-warning-level-4-c4289.md) (nível 4)|extensão não padrão usada: '*var*': a variável de controle de loop declarada no loop for é usada fora do escopo do loop for|
|[C4296](../error-messages/compiler-warnings/compiler-warning-level-4-c4296.md) (nível 4)|'*Operator*': expressão é sempre false|
|[C4339](../error-messages/compiler-warnings/compiler-warning-level-4-c4339.md) (nível 4)|'*Type*': uso de tipo indefinido detectado em metadados CLR-o uso desse tipo pode levar a uma exceção de tempo de execução|
|[C4342](../error-messages/compiler-warnings/compiler-warning-level-1-c4342.md) (nível 1)|alteração de comportamento: '*Function*' chamado, mas um operador membro foi chamado em versões anteriores|
|[C4350](../error-messages/compiler-warnings/compiler-warning-level-1-c4350.md) (nível 1)|alteração de comportamento: '*member1*' chamado em vez de '*membro2*'|
|[C4355](../error-messages/compiler-warnings/compiler-warning-c4355.md)|'this' : usado na lista de inicializadores do membro base|
|[C4365](../error-messages/compiler-warnings/compiler-warning-level-4-c4365.md) (nível 4)|'*Action*': conversão de '*type_1*' para '*type_2*', incompatibilidade de assinada/não assinado|
|C4370 (nível 3)|layout da classe foi alterado de uma versão anterior do compilador devido a empacotamento melhor|
|[C4371](../error-messages/compiler-warnings/c4371.md) (nível 3)|'*ClassName*': o layout da classe pode ter mudado de uma versão anterior do compilador devido ao melhor empacotamento do membro '*Member*'|
|C4388 (nível 4)|incompatibilidade de signed/unsigned|
|[C4412](../error-messages/compiler-warnings/compiler-warning-level-2-c4412.md) (nível 2)|'*Function*': assinatura de função contém tipo '*Type*'; C++ os objetos não são seguros para passar entre o código puro e o misto ou nativo|
|C4426 (nível 1)|os sinalizadores de otimização foram alterados após incluir o cabeçalho, pode ser devido a #pragma Optimize () <sup>14,1</sup>|
|[C4435](../error-messages/compiler-warnings/compiler-warning-level-4-c4435.md) (nível 4)|'*Class1*': O layout do objeto em/vd2 será alterado devido à base virtual '*class2*'|
|[C4437](../error-messages/compiler-warnings/compiler-warning-level-4-c4437.md) (nível 4)|dynamic_cast da base virtual '*Class1*' para '*class2*' poderia falhar em alguns contextos|
|C4444 (nível 3)|top level '__unaligned' não é implementado nesse contexto|
|[C4464](../error-messages/compiler-warnings/c4464.md) (nível 4)|o caminho de inclusão relativo contém '.. '|
|[C4471](../error-messages/compiler-warnings/compiler-warning-level-4-c4471.md) (nível 4)|uma declaração de encaminhamento de uma enumeração sem escopo deve ter um tipo subjacente (int assumido) <sup>Perm</sup>|
|C4472 (nível 1)|'*Identifier*' é uma enumeração nativa: adicionar um especificador de acesso (privado/público) para declarar uma enumeração gerenciada|
|[C4514](../error-messages/compiler-warnings/compiler-warning-level-4-c4514.md) (nível 4)|'*Function*': função embutida não referenciada foi removida|
|[C4536](../error-messages/compiler-warnings/compiler-warning-level-4-c4536.md) (nível 4)|' nome do tipo ': o nome do tipo excede o limite de metadados de '*Limit*' caracteres|
|[C4545](../error-messages/compiler-warnings/compiler-warning-level-1-c4545.md) (nível 1)|expressão antes da vírgula é avaliada para uma função que está ausente em uma lista de argumentos|
|[C4546](../error-messages/compiler-warnings/compiler-warning-level-1-c4546.md) (nível 1)|faltando lista de argumentos na chamada de função antes da vírgula|
|[C4547](../error-messages/compiler-warnings/compiler-warning-level-1-c4547.md) (nível 1)|'*Operator*': o operador antes da vírgula não tem efeito; operador esperado com efeito colateral|
|[C4548](../error-messages/compiler-warnings/compiler-warning-level-1-c4548.md) (nível 1)|expressão antes da vírgula não tem efeito; expressão esperada com efeito colateral|
|[C4549](../error-messages/compiler-warnings/compiler-warning-level-1-c4549.md) (nível 1)|'*operator1*': o operador antes da vírgula não tem efeito; Você pretendia '*operator2*'?|
|[C4555](../error-messages/compiler-warnings/compiler-warning-level-1-c4555.md) (nível 1)|expressão não tem efeito; expressão esperada com efeito colateral|
|[C4557](../error-messages/compiler-warnings/compiler-warning-level-3-c4557.md) (nível 3)|' __assume ' contém efeito '*Effect*'|
|[C4571](../error-messages/compiler-warnings/compiler-warning-level-4-c4571.md) (nível 4)|informação: a semântica catch (...) foi alterada desde o C++ Visual 7,1; as exceções estruturadas (SEH) não são mais detectadas|
|C4574 (nível 4)|'*Identifier*' está definido como ' 0 ': você quis dizer usar ' #if *Identifier*'?|
|C4577 (nível 1)|' noexcept ' usado sem modo de tratamento de exceção especificado; a rescisão na exceção não é garantida. Especificar/EHsc|
|C4582 (nível 4)|'*Type*': o construtor não é chamado implicitamente|
|C4583 (nível 4)|'*Type*': o destruidor não é chamado implicitamente|
|C4587 (nível 1)|'*anonymous_structure*': alteração de comportamento: o construtor não é mais implicitamente chamado|
|C4588 (nível 1)|'*anonymous_structure*': alteração de comportamento: o destruidor não é mais implicitamente chamado|
|[C4596](../error-messages/compiler-warnings/c4596.md) (nível 4)|'*Identifier*': nome qualificado inválido na declaração de membro <sup>14,3</sup> <sup>Perm</sup>|
|C4598 (nível 1 e nível 3)|*cabeçalho*' #include "" ': o *número* de número de cabeçalho no cabeçalho pré-compilado não corresponde à compilação atual nessa posição <sup>14,3</sup>|
|C4599 (nível 3)|'*Option* *Path*': o *número* de número do argumento de linha de comando não corresponde ao cabeçalho pré-compilado <sup>14,3</sup>|
|C4605 (nível 1)|'/D*macro*' especificada na linha de comando atual, mas não foi especificada quando o cabeçalho pré-compilado foi criado|
|[C4608](../error-messages/compiler-warnings/compiler-warning-level-3-c4608.md) (nível 3)|'*union_member*' já foi inicializado por outro membro de União na lista de inicializadores, '*union_member*' <sup>Perm</sup>|
|[C4619](../error-messages/compiler-warnings/compiler-warning-level-3-c4619.md) (nível 3)|aviso de #pragma: não há número de aviso '*número*'|
|[C4623](../error-messages/compiler-warnings/compiler-warning-level-4-c4623.md) (nível 4)|'derived class': construtor padrão não pôde ser gerado porque o construtor padrão de uma classe base está inacessível|
|[C4625](../error-messages/compiler-warnings/compiler-warning-level-4-c4625.md) (nível 4)|'derived class': construtor de cópia não pôde ser gerado porque o construtor de cópia de uma classe base está inacessível|
|[C4626](../error-messages/compiler-warnings/compiler-warning-level-4-c4626.md) (nível 4)|'derived class': operador de atribuição não pôde ser gerado porque o operador de atribuição de uma classe base está inacessível|
|[C4628](../error-messages/compiler-warnings/compiler-warning-level-1-c4628.md) (nível 1)|dígrafos não suportados com -Ze. Sequência de caracteres '*dígrafo*' não interpretada como token alternativo para '*Char*'|
|[C4640](../error-messages/compiler-warnings/compiler-warning-level-3-c4640.md) (nível 3)|'*Instance*': construção de objeto estático local não é thread-safe|
| C4643 (nível 4) | O C++ '*identificador*' de declaração de encaminhamento no namespace std não é permitido pelo padrão. <sup>15.8</sup> |
|C4647 (nível 3)|alteração de comportamento: __is_pod (*Type*) tem um valor diferente em versões anteriores|
|C4654 (nível 4)|O código colocado antes da inclusão da linha de cabeçalho pré-compilado será ignorado. Adicione código ao cabeçalho pré-compilado. <sup>14.1</sup>|
|[C4668](../error-messages/compiler-warnings/compiler-warning-level-4-c4668.md) (nível 4)|'*Symbol*' não está definido como uma macro de pré-processador, substituindo por ' 0 ' para '*diretivas*'|
|[C4682](../error-messages/compiler-warnings/compiler-warning-level-4-c4682.md) (nível 4)|'*Symbol*': nenhum atributo de parâmetro direcional especificado, padronizando para [in]|
|[C4686](../error-messages/compiler-warnings/compiler-warning-level-3-c4686.md) (nível 3)|'*tipo definido pelo usuário*': possível alteração no comportamento, alteração na Convenção de chamada de retorno UDT|
|[C4692](../error-messages/compiler-warnings/compiler-warning-level-1-c4692.md) (nível 1)|'*Function*': assinatura de membro não privado contém tipo nativo de assembly privado '*native_type*'|
|[C4710](../error-messages/compiler-warnings/compiler-warning-level-4-c4710.md) (nível 4)|'*Function*': função não embutida|
|[C4738](../error-messages/compiler-warnings/compiler-warning-level-3-c4738.md) (nível 3)|armazenando o resultado float de 32 bits na memória, possível perda de desempenho|
|[C4746](../error-messages/compiler-warnings/compiler-warning-c4746.md)|o acesso volátil de '*expression*' está sujeito a/volatile\<:&#124;ISO MS > Setting; considere usar funções intrínsecas __iso_volatile_load/Store|
|C4749 (nível 4)|com suporte condicional: offsetof aplicado ao tipo de layout não padrão '*Type*'|
|C4767 (nível 4)|o nome da seção '*Symbol*' tem mais de 8 caracteres e será truncado pelo vinculador|
|C4768 (nível 3)|atributos over_ declspec antes da especificação de vinculação serem ignorados|
|C4774 (nível 4)|'*String*': cadeia de caracteres de formato esperada no *número* de argumento não é um literal de cadeia de caracteres|
|C4777 (nível 4)|'*Function*': a cadeia de caracteres de formato '*String*' requer um argumento do tipo '*type1*', mas o *número* do argumento Variadic tem o tipo '*type2*'|
|C4786 (nível 3)|'*Symbol*': o nome do objeto foi truncado para '*Number*' caracteres nas informações de depuração|
| [C4800](../error-messages/compiler-warnings/compiler-warning-level-3-c4800.md) (nível 4) | Conversão implícita de '*Type*' para bool. Possível perda de informações <sup>16,0</sup> |
|[C4820](../error-messages/compiler-warnings/compiler-warning-level-4-c4820.md) (nível 4)|'*bytes*' bytes de preenchimento adicionados após a construção '*member_name*'|
| [C4822](../error-messages/compiler-warnings/compiler-warning-level-1-c4822.md) (nível 1) | '*Member*': a função de membro de classe local não tem um corpo |
|C4826 (nível 2)|A conversão de '*type1*' em '*type2*' é um sinal estendido. Isso pode causar um comportamento de tempo de execução inesperado.|
|C4837 (nível 4)|trigraph detectado: '?? *caractere*' substituído por '*caractere*'|
|C4841 (nível 4)|extensão não padrão usada: designador de membro composto usado em offsetof|
|C4842 (nível 4)|o resultado de ' offsetof ' aplicado a um tipo usando herança múltipla não é garantido como consistente entre as versões do compilador|
|[C4868](../error-messages/compiler-warnings/compiler-warning-c4868.md) (nível 4)|o compilador '_File_(*line_number*) ' não pode impor a ordem de avaliação da esquerda para a direita na lista de inicialização de chaves|
|[C4905](../error-messages/compiler-warnings/compiler-warning-level-1-c4905.md) (nível 1)|literal amplo de cadeia de caracteres convertido em 'LPSTR'|
|[C4906](../error-messages/compiler-warnings/compiler-warning-level-1-c4906.md) (nível 1)|literal de cadeia de caracteres convertido em 'LPWSTR'|
|[C4917](../error-messages/compiler-warnings/compiler-warning-level-1-c4917.md) (nível 1)|'declarador ': um GUID só pode ser associado a uma classe, interface ou namespace|
|[C4928](../error-messages/compiler-warnings/compiler-warning-level-1-c4928.md) (nível 1)|inicialização de cópia ilegal; mais de uma conversão definida pelo usuário foi implicitamente aplicada|
|[C4931](../error-messages/compiler-warnings/compiler-warning-level-4-c4931.md) (nível 4)|estamos supondo que a biblioteca de tipos foi criada para ponteiros de bit por número|
|[C4946](../error-messages/compiler-warnings/compiler-warning-level-1-c4946.md) (nível 1)|reinterpret_cast usado entre classes relacionadas: '*Class1*' e '*class2*'|
|C4962|'*Function*': otimizações guiadas por perfil desabilitadas porque otimizações fizeram com que os dados de perfil se tornem inconsistentes|
|[C4986](../error-messages/compiler-warnings/compiler-warning-c4986.md) (nível 4)|'*Symbol*': a especificação de exceção não corresponde à declaração anterior|
|C4987 (nível 4)|extensão não padrão usada: 'throw (...)'|
|C4988 (nível 4)|'*Symbol*': variável declarada fora do escopo de classe/função|
|C5022|'*Type*': vários construtores de movimentação especificados|
|C5023|'*Type*': vários operadores de atribuição de movimento especificados|
|C5024 (nível 4)|'*Type*': o construtor de movimentação foi implicitamente definido como excluído|
|C5025 (nível 4)|'*Type*': o operador de atribuição de movimento foi implicitamente definido como excluído|
|C5026 (nível 1 e nível 4)|'*Type*': o construtor de movimentação foi implicitamente definido como excluído|
|C5027 (nível 1 e nível 4)|'*Type*': o operador de atribuição de movimento foi implicitamente definido como excluído|
|C5029 (nível 4)|extensão não padrão usada: atributos de alinhamento C++ em aplicar a variáveis, membros de dados e tipos de marca somente|
|C5031 (nível 4)|aviso de #pragma (pop): provável incompatibilidade, estado de aviso de pop-up enviado por push em um arquivo diferente <sup>14,1</sup>|
|C5032 (nível 4)|detectado #pragma Aviso (push) sem aviso de #pragma correspondente (pop) <sup>14,1</sup>|
|C5034|o uso de intrínseco '*intrínseco*' faz com que a *função* de função seja compilada como código de convidado <sup>15,3</sup>|
|C5035|o uso do recurso '*Feature*' faz com que a *função* de função seja compilada como código de convidado <sup>15,3</sup>|
|C5036 (nível 1)|conversão de ponteiro de função varargs ao compilar com/Hybrid: x86arm64 '*type1*' para '*type2*' <sup>15,3</sup>|
|[C5038](../error-messages/compiler-warnings/c5038.md) (nível 4)|o membro de dados '*member1*' será inicializado após o membro de dados '*membro2*' <sup>15,3</sup>|
|C5039 (nível 4)|'*Function*': ponteiro ou referência para gerar potencialmente a função passada para a função C externa em-EHc. O comportamento indefinido poderá ocorrer se essa função lançar uma exceção. <sup>15,5</sup>|
|C5042 (nível 3)|'*Function*': declarações de função em escopo de bloco não podem ser especificadas ' inline C++' no Standard; remover especificador ' inline ' <sup>15,5</sup>|
|[C5045](../error-messages/compiler-warnings/c5045.md)|O compilador irá inserir a mitigação de Spectre para a carga de memória se a opção/Qspectre especificou <sup>15,7</sup>|

<sup>14,1</sup> este aviso está disponível a partir do Visual Studio 2015 atualização 1.<br/>
<sup>14,3</sup> este aviso está disponível a partir do Visual Studio 2015 atualização 3.<br/>
<sup>15,3</sup> este aviso está disponível a partir do Visual Studio 2017 versão 15,3.<br/>
<sup>15,5</sup> este aviso está disponível a partir do Visual Studio 2017 versão 15,5.<br/>
<sup>15,7</sup> este aviso está disponível a partir do Visual Studio 2017 versão 15,7.<br/>
<sup>15,8</sup> este aviso está disponível a partir do Visual Studio 2017 versão 15,8.<br/>
::: moniker range=">= vs-2019"
<sup>16,0</sup> este aviso está disponível a partir do Visual Studio 2019 RTM.<br/>
::: moniker-end
<sup>Perm</sup> Esse aviso será desativado, a menos que a opção de compilador [/permissive-](../build/reference/permissive-standards-conformance.md) esteja definida.

## <a name="warnings-off-by-default-in-earlier-versions"></a>Avisos desativados por padrão em versões anteriores

Esses avisos estavam desativados por padrão nas versões do compilador antes do Visual Studio 2015:

|||
|-|-|
|[C4302](../error-messages/compiler-warnings/compiler-warning-level-2-c4302.md) (nível 2)|'*Conversion*': truncamento de '*type1*' para '*type2*'|
|[C4311](../error-messages/compiler-warnings/compiler-warning-level-1-c4311.md) (nível 1)|'*Variable*': truncamento de ponteiro de '*Type*' para '*Type*'|
|[C4312](../error-messages/compiler-warnings/compiler-warning-level-1-c4312.md) (nível 1)|'*Operation*': conversão de '*type1*' para '*type2*' de tamanho maior|
|[C4319](../error-messages/compiler-warnings/compiler-warning-level-1-c4319.md) (nível 1)|'*Operator*': sem estender '*type1*' para '*type2*' de tamanho maior|

Esse aviso foi desativado por padrão nas versões do compilador antes do Visual Studio 2012:

|||
|-|-|
|[C4431](../error-messages/compiler-warnings/compiler-warning-level-4-c4431.md) (nível 4)|faltando especificador de tipo - int assumido. Observação: C não dá mais suporte a default-int|

## <a name="see-also"></a>Consulte também

[warning](../preprocessor/warning.md)