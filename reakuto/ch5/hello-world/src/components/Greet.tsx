type Props = { name: string; times?: number };

//const Greet: React.FC<Props> = (props) => {
//	const { name, times = 1 } = props;

const Greet: React.FC<Props> = ({ name, times = 1 }) => {
	return (
		<>
			{[...Array(times).keys()].map((i) => (
				<p key={i}>Hello, {name}!</p>
			))}
		</>
	);
};
export default Greet;
